// https://school.programmers.co.kr/learn/courses/30/lessons/12904

function solution(s) {
  for (let len = s.length; ; len--) {
    for (let start = 0; start < s.length - len + 1; start++) {
      if (isPalindrome(s.slice(start, start + len))) {
        return len;
      }
    }
  }
}

function isPalindrome(string) {
  let flag = true;

  for (let i = 0; i < Math.floor(string.length / 2); i++) {
    if (string[i] !== string[string.length - 1 - i]) {
      flag = false;
      break;
    }
  }

  return flag;
}

/*
    모든 subString을 팰린드롬인지 test하는 방법
*/
