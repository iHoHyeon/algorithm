// https://school.programmers.co.kr/learn/courses/30/lessons/12941

const solution = (A, B) => {
  const ascA = A.sort((a, b) => a - b);
  const descB = B.sort((a, b) => b - a);

  return ascA.reduce((acc, v, idx) => acc + v * descB[idx], 0);
};
