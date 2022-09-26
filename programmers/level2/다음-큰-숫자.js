// https://school.programmers.co.kr/learn/courses/30/lessons/12911

const getOneCount = (num) => (num.toString(2).match(/1/g) ?? '').length;

const solution = (n) => {
  const one_cnt = getOneCount(n);

  let now_cnt = -1;

  while (now_cnt !== one_cnt) {
    n = n + 1;

    now_cnt = getOneCount(n);
  }

  return n;
};
