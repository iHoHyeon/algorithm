// https://programmers.co.kr/learn/courses/30/lessons/42576

function solution(participant, completion) {
  const peopleMap = new Map();

  for (const a of participant) {
    peopleMap.set(a, (peopleMap.get(a) || 0) + 1);
  }

  for (const a of completion) {
    const valueA = peopleMap.get(a);
    valueA === 1 ? peopleMap.delete(a) : peopleMap.set(a, valueA - 1);
  }

  return Array.from(peopleMap.keys())[0];
}
