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

	masks = [4]Cursor{
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0},
	}
)

type Cursor = [2]int
type TomatoBox = [][]int

type Tracker struct {
	day    int
	cursor Cursor
}

func NewTomatoBox(s *bufio.Scanner) (TomatoBox, []Cursor, int) {
	var width, height int
	if s.Scan() {
		output := strings.Fields(s.Text())
		width, _ = strconv.Atoi(output[0])
		height, _ = strconv.Atoi(output[1])
	}

	var tomatoes int
	box := make([][]int, height)
	riped := make([]Cursor, 0, width*height)
	for i := range box {
		box[i] = make([]int, width)
		if s.Scan() {
			for j, tomato := range strings.Fields(s.Text()) {
				box[i][j], _ = strconv.Atoi(tomato)
				if box[i][j] == 1 {
					riped = append(riped, Cursor{i, j})
					tomatoes++
				} else if box[i][j] == 0 {
					tomatoes++
				}
			}
		}
	}

	return box, riped, tomatoes
}

func isValidCursor(box TomatoBox, c Cursor) bool {
	return 0 <= c[0] && c[0] < len(box) &&
		0 <= c[1] && c[1] < len(box[0])
}

func solve(box TomatoBox, riped []Cursor, tomatoes int) int {
	var days, current int

	queue := make(chan Tracker, len(box)*len(box[0]))
	for _, c := range riped {
		queue <- Tracker{0, c}
		current++
	}

	for len(queue) > 0 {
		v := <-queue
		for _, mask := range masks {
			c := Cursor{v.cursor[0] + mask[0], v.cursor[1] + mask[1]}
			if isValidCursor(box, c) && box[c[0]][c[1]] == 0 {
				box[c[0]][c[1]] = 1
				queue <- Tracker{v.day + 1, c}
				current++
				if days < v.day+1 {
					days = v.day + 1
				}
			}
		}
	}

	if tomatoes != current {
		return -1
	}
	return days
}

func main() {
	defer writer.Flush()
	fmt.Fprintln(writer, solve(NewTomatoBox(scanner)))
}
