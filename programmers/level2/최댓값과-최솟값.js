// https://school.programmers.co.kr/learn/courses/30/lessons/12939

const solution = (s) => {
  const { max, min } = s.split(' ').reduce((acc, int) => ({ max: Math.max(acc.max, Number(int)), min: Math.min(acc.min, Number(int)) }), {
    max: -Infinity,
    min: Infinity,
  });

  return `${min} ${max}`;
};

/*
그냥 s의 Math.min, Math.max 를 뽑으면 되는데, 너무 어렵게 생각했다..

function solution(s) {
    const arr = s.split(' ');

    return Math.min(...arr)+' '+Math.max(...arr);
}
*/
