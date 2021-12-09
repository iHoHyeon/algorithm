// https://programmers.co.kr/learn/courses/30/lessons/72410

const pipe =
  (param) =>
  (...fn) =>
    fn.reduce((res, fn) => fn(res), param);
const step1 = (newId) => newId.toLowerCase();
const step2 = (newId) => newId.replace(/[^a-z0-9\-\_\.]/g, '');
const step3 = (newId) => newId.replace(/(\.+)/g, '.');
const step4 = (newId) => newId.replace(/^\.|\.$/g, '');
const step5 = (newId) => newId || 'a';
const step6 = (newId) => newId.slice(0, 15).replace(/\.$/, '');
const step7 = (newId) => (newId[2] ? newId : newId + newId.substr(newId.length - 1, 1).repeat(3 - newId.length));

const solution = (newId) => pipe(newId)(step1, step2, step3, step4, step5, step6, step7);

/*
  효율성 면에서는 잘 모르겠다.
  다만 1~7단계를 순차적으로 in - out 을 반복하여, pipe 함수를 작성해주었다.
  pipe로 작성하지 않고 메서드들을 체이닝해도 됨

  정규표현식을 많이 참고하였다. 알고리즘이라기 보다는 구현 문제라고 생각
  정규식을 검색없이 구현하기가 어려웠다.
  정규식 정리 / 연습을 많이 해보고 익숙해져야겠다고 느꼈다

  검색없이 구현가능하도록 연습해야하나..? 검색하여 적용할 정도로 해야하나 그 경계가 어딘지 모르겠으나 정리해보자

  정규표현식 참고 링크
  https://velog.io/@suuhyeony/JS-%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8-%EC%A0%95%EA%B7%9C%ED%91%9C%ED%98%84%EC%8B%9D


  String.prototype.repeat()
  https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/String/repeat
  

  # 풀이 후

  => styp2에서 /[^a-z0-9\-\_\.]/ 대신에 /[^\w-.]/ 를 사용해도 됨 (\w : 알파벳, 숫자, _)
  
  => step3에서 /(\.+)/의 그룹을 묶지 않아도 됨 : /\.+/

  => step5에서 .replace(/^$/, 'a')을 사용해도 됨 /^$/ : ^$는 의미 상 빈 문자열괴 매칭됨

  => step7에서 repeat() 말고 padEnd()를 사용해도 됨
  */
