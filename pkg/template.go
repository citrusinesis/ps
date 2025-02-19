package pkg

import (
	"bufio"
	"os"
	"strings"
)

var scanner = bufio.NewScanner(os.Stdin)
var writer = bufio.NewWriter(os.Stdout)
var builder strings.Builder

func init2DSlice[T any](x, y uint) [][]T {
	result := make([][]T, x)
	for i := range result {
		result[i] = make([]T, y)
	}
	return result
}
