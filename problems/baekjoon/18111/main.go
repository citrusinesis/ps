package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

type Field = [][]int

func parseField(s *bufio.Scanner) (Field, int) {
	var height, width, inventory int
	if s.Scan() {
		parsed := strings.Fields(s.Text())
		height, _ = strconv.Atoi(parsed[0])
		width, _ = strconv.Atoi(parsed[1])
		inventory, _ = strconv.Atoi(parsed[2])
	}

	field := make([][]int, height)
	for i := 0; i < height; i++ {
		field[i] = make([]int, width)
		if s.Scan() {
			parsed := strings.Fields(s.Text())
			for j, v := range parsed {
				field[i][j], _ = strconv.Atoi(v)
			}
		}
	}

	return field, inventory
}

func solve(field Field, inventory int) (int, int) {
	minTime := int(1e9)
	bestHeight := -1

	for targetHeight := 0; targetHeight <= 256; targetHeight++ {
		removeBlocks := 0
		addBlocks := 0

		for _, row := range field {
			for _, item := range row {
				if item > targetHeight {
					removeBlocks += item - targetHeight
				} else {
					addBlocks += targetHeight - item
				}
			}
		}

		if addBlocks <= removeBlocks+inventory {
			time := 2*removeBlocks + addBlocks
			if time < minTime {
				minTime = time
				bestHeight = targetHeight
			} else if time == minTime && targetHeight > bestHeight {
				bestHeight = targetHeight
			}
		}
	}

	return minTime, bestHeight
}

func main() {
	defer writer.Flush()
	field, inventory := parseField(scanner)
	time, height := solve(field, inventory)
	fmt.Fprintln(writer, time, height)
}
