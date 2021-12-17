// https://programmers.co.kr/learn/courses/30/lessons/43238

const solution = (n, times) => {
  let start = 0;
  let end = Math.max(...times) * n;
  let mid;

  while (start < end) {
    mid = Math.floor((start + end) / 2);
    const tempN = times.reduce((acc, time) => acc + Math.floor(mid / time), 0);
    if (tempN < n) start = mid + 1;
    else end = mid;
  }
  return start;
};

/*
  최소: 0, 최대: times.max * n 으로 최적의 return 을 이분탐색한다.
  return을 times의 각 원소로 나눈 몫의 합이 n이 되면서 가장 작은 값이 정답이 됨을 이용

  이분탐색을 진행하는 방법에 대해서 학습해보자

  mid 값을 어떻게 (+1 or -1) 할 건지 큰 틀은 같지만 여러 사소한 차이가 있으니
  다른 사람들의 코드도 참고해서 정리해보기
*/
