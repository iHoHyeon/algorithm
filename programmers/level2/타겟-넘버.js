// https://programmers.co.kr/learn/courses/30/lessons/43165

function solution(numbers, target) {
  let res = 0;
  const loop = (idx, now) => {
    if (idx === numbers.length) return now === target && res++;

    loop(idx + 1, now + numbers[idx]);
    loop(idx + 1, now - numbers[idx]);
  };
  loop(0, 0);
  return res;
}

/*
  그냥 모든 경우의 수를 재귀적으로 확인해주었다. 2^n 이므로 최대 2^20가지의 경우의 수
*/
