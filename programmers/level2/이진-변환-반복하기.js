// https://school.programmers.co.kr/learn/courses/30/lessons/70129

function solution(s) {
  let convert_cnt = 0;
  let zero_cnt = 0;

  while (s !== '1') {
    [...s].forEach((w) => w === '0' && zero_cnt++);
    s = s.replaceAll('0', '');

    s = s.length.toString(2);
    convert_cnt++;
  }

  return [convert_cnt, zero_cnt];
}
