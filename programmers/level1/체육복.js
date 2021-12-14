// https://programmers.co.kr/learn/courses/30/lessons/42862

const solution = (n, lost, reserve) => {
  lost.sort((a, b) => a - b);
  reserve.sort((a, b) => a - b);
  const lr = new Set();
  lost.forEach((l) => reserve.includes(l) && lr.add(l));
  lost.forEach((l) => {
    reserve.some((r) => !lr.has(l) && (l === r - 1 || l === r + 1) && !lr.has(r) && lr.add(r));
  });

  return n - lost.length + lr.size;
};

/*
  Set을 이용해서 이미 빌려준 사람의 번호를 저장해놓고 lost를 순회한다
*/
