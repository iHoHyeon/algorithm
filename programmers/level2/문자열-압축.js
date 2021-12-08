// https://programmers.co.kr/learn/courses/30/lessons/60057

function solution(s) {
  let ans = s.length;
  for (let i = 1; i < s.length; i++) {
    let nowCase = 0;
    let nowS;
    let nowAns = s.length;
    let start = 0;
    let end = i;
    nowS = s.slice(start, end);
    while (end + i <= s.length) {
      start += i;
      end += i;
      if (nowS === s.slice(start, end)) {
        nowAns -= i;
        nowAns += !nowCase ? 1 : 0;
        nowCase++;
        if (nowCase === 9) nowAns++;
        if (nowCase === 99) nowAns++;
        if (nowCase === 999) nowAns++;
      } else {
        nowCase = 0;
      }
      nowS = s.slice(start, end);
    }
    ans = Math.min(nowAns, ans);
  }
  return ans;
}

/*
  예외처리가 관건, 10 / 100 / 1000이 나오는 경우

  + 다른 사람들 풀이 참고해보기
*/
