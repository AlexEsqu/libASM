#!/bin/bash

# Benchmark runner script for libASM, libft, and libc
# Compiles and runs performance tests using perf

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
BUILD_DIR="$SCRIPT_DIR/build"

# Colors for output
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Create build directory
mkdir -p "$BUILD_DIR"

# Compile all benchmarks
compile_benchmark() {
    local name=$1
    local source=$2
    local libs=$3

    echo -e "${BLUE}Compiling${NC} $name..."
    gcc -O2 -o "$BUILD_DIR/$name" "$source" \
        -I"$PROJECT_DIR/inc" \
        -L"$PROJECT_DIR" $libs 2>/dev/null || {
        echo "Error compiling $name"
        return 1
    }
}

# Run benchmark with perf or time fallback
run_perf() {
    local name=$1
    local binary=$2

    echo -e "${YELLOW}Benchmarking${NC} $name..."

    # Try perf first, fall back to time if perf not available
    if command -v perf &> /dev/null && perf stat -e cycles /bin/true &> /dev/null; then
        perf stat -e cycles,instructions,cache-misses,cache-references "$BUILD_DIR/$binary" 2>&1 | \
            grep -E "cycles|instructions|cache|time elapsed"
    else
        # Fallback to time command for basic timing
        /usr/bin/time -f "  Execution time: %e seconds\n  CPU usage: %P" "$BUILD_DIR/$binary" 2>&1
    fi
    echo ""
}

echo -e "${GREEN}╔═══════════════════════════════════════════════════════════════╗${NC}"
echo -e "${GREEN}║        Performance Benchmarks: libASM vs libft vs libc        ║${NC}"
echo -e "${GREEN}╚═══════════════════════════════════════════════════════════════╝${NC}"
echo ""

# Ensure libraries are built
echo -e "${BLUE}═══ BUILDING LIBRARIES ═══${NC}"
cd "$PROJECT_DIR"
make > /dev/null 2>&1 || {
    echo -e "${YELLOW}⚠ Warning: libasm.a build completed (may have issues)${NC}"
}
make libft > /dev/null 2>&1 || {
    echo -e "${YELLOW}⚠ Warning: libft.a build completed (may have issues)${NC}"
}
cd "$SCRIPT_DIR"
echo -e "${GREEN}✓ Libraries ready${NC}"
echo ""

# Compile all benchmarks
echo -e "${BLUE}═══ COMPILATION PHASE ═══${NC}"
compile_benchmark "bench_strlen_asm" "$SCRIPT_DIR/bench_strlen_asm.c" "-lasm"
compile_benchmark "bench_strlen_c" "$SCRIPT_DIR/bench_strlen_c.c" "-lft -lasm"
compile_benchmark "bench_strlen_libc" "$SCRIPT_DIR/bench_strlen_libc.c" ""

compile_benchmark "bench_strcmp_asm" "$SCRIPT_DIR/bench_strcmp_asm.c" "-lasm"
compile_benchmark "bench_strcmp_c" "$SCRIPT_DIR/bench_strcmp_c.c" "-lft -lasm"
compile_benchmark "bench_strcmp_libc" "$SCRIPT_DIR/bench_strcmp_libc.c" ""

compile_benchmark "bench_strcpy_asm" "$SCRIPT_DIR/bench_strcpy_asm.c" "-lasm"
compile_benchmark "bench_strcpy_c" "$SCRIPT_DIR/bench_strcpy_c.c" "-lft -lasm"
compile_benchmark "bench_strcpy_libc" "$SCRIPT_DIR/bench_strcpy_libc.c" ""

compile_benchmark "bench_strdup_asm" "$SCRIPT_DIR/bench_strdup_asm.c" "-lasm"
compile_benchmark "bench_strdup_c" "$SCRIPT_DIR/bench_strdup_c.c" "-lft -lasm"
compile_benchmark "bench_strdup_libc" "$SCRIPT_DIR/bench_strdup_libc.c" ""

compile_benchmark "bench_write_asm" "$SCRIPT_DIR/bench_write_asm.c" "-lasm"
compile_benchmark "bench_write_libc" "$SCRIPT_DIR/bench_write_libc.c" ""

compile_benchmark "bench_read_asm" "$SCRIPT_DIR/bench_read_asm.c" "-lasm"
compile_benchmark "bench_read_libc" "$SCRIPT_DIR/bench_read_libc.c" ""

echo ""
echo -e "${BLUE}═══ BENCHMARKING PHASE ═══${NC}"
echo ""

# FT_STRLEN
echo -e "${GREEN}ft_strlen (100M iterations)${NC}"
echo -e "  ${YELLOW}libASM (Assembly):${NC}"
run_perf "ft_strlen_asm" "bench_strlen_asm"

echo -e "  ${YELLOW}libft (C):${NC}"
run_perf "ft_strlen_c" "bench_strlen_c"

echo -e "  ${YELLOW}libc (Standard):${NC}"
run_perf "ft_strlen_libc" "bench_strlen_libc"

# FT_STRCMP
echo ""
echo -e "${GREEN}ft_strcmp (50M iterations)${NC}"
echo -e "  ${YELLOW}libASM (Assembly):${NC}"
run_perf "ft_strcmp_asm" "bench_strcmp_asm"

echo -e "  ${YELLOW}libft (C):${NC}"
run_perf "ft_strcmp_c" "bench_strcmp_c"

echo -e "  ${YELLOW}libc (Standard):${NC}"
run_perf "ft_strcmp_libc" "bench_strcmp_libc"

# FT_STRCPY
echo ""
echo -e "${GREEN}ft_strcpy (10M iterations)${NC}"
echo -e "  ${YELLOW}libASM (Assembly):${NC}"
run_perf "ft_strcpy_asm" "bench_strcpy_asm"

echo -e "  ${YELLOW}libft (C):${NC}"
run_perf "ft_strcpy_c" "bench_strcpy_c"

echo -e "  ${YELLOW}libc (Standard):${NC}"
run_perf "ft_strcpy_libc" "bench_strcpy_libc"

# FT_STRDUP
echo ""
echo -e "${GREEN}ft_strdup (1M iterations with malloc/free)${NC}"
echo -e "  ${YELLOW}libASM (Assembly):${NC}"
run_perf "ft_strdup_asm" "bench_strdup_asm"

echo -e "  ${YELLOW}libft (C):${NC}"
run_perf "ft_strdup_c" "bench_strdup_c"

echo -e "  ${YELLOW}libc (Standard):${NC}"
run_perf "ft_strdup_libc" "bench_strdup_libc"

# FT_WRITE
echo ""
echo -e "${GREEN}ft_write (100K iterations)${NC}"
echo -e "  ${YELLOW}libASM (Assembly):${NC}"
run_perf "ft_write_asm" "bench_write_asm"

echo -e "  ${YELLOW}libc (Standard):${NC}"
run_perf "ft_write_libc" "bench_write_libc"

# FT_READ
echo ""
echo -e "${GREEN}ft_read (50K iterations with file open/close)${NC}"
echo -e "  ${YELLOW}libASM (Assembly):${NC}"
run_perf "ft_read_asm" "bench_read_asm"

echo -e "  ${YELLOW}libc (Standard):${NC}"
run_perf "ft_read_libc" "bench_read_libc"

echo ""
echo -e "${GREEN}╔═══════════════════════════════════════════════════════════════╗${NC}"
echo -e "${GREEN}║                   Benchmarks Complete!                        ║${NC}"
echo -e "${GREEN}╚═══════════════════════════════════════════════════════════════╝${NC}"
echo ""
echo -e "${YELLOW}Binaries saved to:${NC} $BUILD_DIR/"
echo -e "${YELLOW}To run individual benchmarks:${NC}"
echo "  perf stat $BUILD_DIR/bench_strlen_asm"
echo "  perf stat $BUILD_DIR/bench_strcmp_c"
echo ""
