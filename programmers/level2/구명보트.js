// https://school.programmers.co.kr/learn/courses/30/lessons/42885

function solution(people, limit) {
  people.sort((a, b) => a - b);

  let cnt = 0;

  let front = 0;
  let last = people.length;

  while (last > front) {
    cnt++;

    const now = people.pop();
    last--;

    if (now + people[front] <= limit) {
      front++;
    }
  }

  return cnt;
}

/*

  보트는 최대 2명씩 밖에 탈 수 없다.
  따라서 가장 무거운 사람부터 태우며, 
  가벼운 순으로 2명씩 탈 수 있는 경우가 가능한지 확인해준다.

  * shift() 연산이 효율성 통과를 하지 못하여 front / last 포인터를 두어서 해결했다.
*/
