// https://school.programmers.co.kr/learn/courses/30/lessons/12951

const solution = (s) =>
  s
    .toLowerCase()
    .split(' ')
    .map((v) => v.charAt(0).toUpperCase() + v.substring(1))
    .join(' ');

console.log(solution('3people unFollowed me'));
