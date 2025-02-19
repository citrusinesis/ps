package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
type HousingMap struct {
	size int

	housingMap [][]bool
	visited    [][]bool

	complexes map[Cursor][]Cursor
}

func NewHousingMap(s *bufio.Scanner) *HousingMap {
	var size int
	if s.Scan() {
		size, _ = strconv.Atoi(s.Text())
	}

	housingMap := make([][]bool, size)
	for i := range housingMap {
		housingMap[i] = make([]bool, size)
		if s.Scan() {
			for j, house := range strings.Split(s.Text(), "") {
				if house == "0" {
					housingMap[i][j] = false
				} else {
					housingMap[i][j] = true
				}
			}
		}
	}

	visited := make([][]bool, size)
	for i := range visited {
		visited[i] = make([]bool, size)
	}

	return &HousingMap{
		size:       size,
		housingMap: housingMap,
		visited:    visited,
		complexes:  make(map[Cursor][]Cursor),
	}
}

func (hm *HousingMap) IsVisited(c Cursor) bool {
	return hm.visited[c[0]][c[1]]
}

func (hm *HousingMap) IsValidHouse(c Cursor) bool {
	return 0 <= c[0] && c[0] < hm.size &&
		0 <= c[1] && c[1] < hm.size &&
		hm.housingMap[c[0]][c[1]]
}

func (hm *HousingMap) SearchAdjacentHouse(start Cursor) {
	queue := make(chan Cursor, hm.size*hm.size)
	queue <- start
	hm.visited[start[0]][start[1]] = true

	for len(queue) > 0 {
		v := <-queue

		for _, mask := range masks {
			c := Cursor{v[0] + mask[0], v[1] + mask[1]}
			if hm.IsValidHouse(c) && !hm.IsVisited(c) {
				hm.visited[c[0]][c[1]] = true
				queue <- c
			}
		}

		hm.complexes[start] = append(hm.complexes[start], v)
	}
}

func solve(hm *HousingMap) []int {
	for i, row := range hm.housingMap {
		for j, house := range row {
			c := Cursor{i, j}
			if hm.IsVisited(c) || !house {
				continue
			}
			hm.SearchAdjacentHouse(c)
		}
	}

	var result []int
	for _, houseComplex := range hm.complexes {
		result = append(result, len(houseComplex))
	}
	sort.Ints(result)

	return result
}

func main() {
	housingMap := NewHousingMap(scanner)
	defer writer.Flush()

	result := solve(housingMap)
	fmt.Fprintln(writer, len(result))
	for _, n := range result {
		fmt.Fprintln(writer, n)
	}
}
