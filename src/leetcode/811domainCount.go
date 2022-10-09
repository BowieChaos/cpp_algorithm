package main

import (
	"fmt"
	"strconv"
	"strings"
)

func subdomainVisits(cpdomains []string) []string {
	mp := make(map[string]int, 0)
	for _, v := range cpdomains {
		splits := strings.Split(v, " ")
		num, _ := strconv.Atoi(splits[0])

		for {
			mp[splits[1]] += num
			index := strings.Index(splits[1], ".")
			if index < 0 {
				break
			}
			splits[1] = splits[1][index+1:]
		}
	}

	ret := make([]string, 0, len(mp))

	for k, v := range mp {
		ret = append(ret, fmt.Sprintf("%d %s", v, k))
	}
	return ret
}
