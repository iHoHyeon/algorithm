// https://programmers.co.kr/learn/courses/30/lessons/81301

const m = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];

const solution = (s) => Number(m.reduce((_, $, i) => _.replace(new RegExp($, 'g'), i), s));

// 정규표현식에 변수 string을 사용하고 싶다면 RegExp를 이용!
