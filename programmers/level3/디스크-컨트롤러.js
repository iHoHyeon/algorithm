// https://programmers.co.kr/learn/courses/30/lessons/42627

const solution = (jobs) => {
  jobs.sort((a, b) => a[0] - b[0]);

  let pivot = 0;
  let timer = 0;
  let res = 0;

  const waiting = [];
  while (pivot < jobs.length || waiting.length > 0) {
    for (pivot; pivot < jobs.length; pivot++) {
      if (jobs[pivot][0] <= timer) {
        waiting.push(jobs[pivot]);
      } else break;
    }

    waiting.sort((a, b) => a[1] - b[1]);

    if (waiting.length === 0) timer = jobs[pivot][0];
    else {
      const [s, e] = waiting.shift();
      timer += e;
      res += timer - s;
    }
  }
  return Math.floor(res / jobs.length);
};

/*
  하나의 작업이 이루어지는 동안 대기중인 큐(waiting)에 들어있는 작업들은
  매 작업이 끝날 때마다 갱신해주어야 한다.

  우선순위 큐 자료구조가 있었다면 더 간단했을 문제..
*/
