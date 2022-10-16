package main

import (
	"strconv"
	"strings"
)

// NC113 验证IP地址
// https://www.nowcoder.com/practice/55fb3c68d08d46119f76ae2df7566880?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

/**
 * 验证IP地址
 * @param IP string字符串 一个IP地址字符串
 * @return string字符串
 */
func solve(IP string) string {
	// write code here
	if !strings.Contains(IP, ".") && !strings.Contains(IP, ":") {
		return "Neither"
	}
	if strings.Contains(IP, ".") {
		ips := strings.Split(IP, ".")
		if len(ips) != 4 {
			return "Neither"

		}
		for _, v := range ips {
			if v[0] == '0' {
				return "Neither"
			}
			ip_i, err := strconv.Atoi(v)
			if err != nil {
				return "Neither"
			}
			if ip_i <= 0 || ip_i >= 256 {
				return "Neither"
			}

		}
		return "IPv4"
	}

	ips := strings.Split(IP, ":")
	if len(ips) != 8 {
		return "Neither"
	}
	for _, v := range ips {
		if len(v) > 4 || len(v) == 0 {
			return "Neither"
		}
		for _, c := range v {
			if !haveC(c) {
				return "Neither"
			}
		}
	}
	return "IPv6"
}

func haveC(c rune) bool {
	return strings.ContainsRune("0123456789ABCDEFabcdef", c)
}
