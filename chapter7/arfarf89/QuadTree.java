/**
 * Created by chaelee on 2016. 3. 31..
 */
public class QuadTree {
    public static String flip(String quadTree) {
        if (quadTree.charAt(0) != 'x') {
            return quadTree.charAt(0) + "";
        }

        // 4분할 된 작은문제를 저장할 곳
        String reversedString[] = new String[4];

        // 0번째 index는 'x'
        int beginIndex = 1;

        // 왼쪽 위
        reversedString[0] = flip(quadTree.substring(beginIndex));
        // index 위치 수정
        beginIndex += reversedString[0].length();

        // 오른쪽 위
        reversedString[1] = flip(quadTree.substring(beginIndex));
        beginIndex += reversedString[1].length();

        // 왼쪽 아래
        reversedString[2] = flip(quadTree.substring(beginIndex));
        beginIndex += reversedString[2].length();

        // 오른쪽 아래
        reversedString[3] = flip(quadTree.substring(beginIndex));
        beginIndex += reversedString[3].length();

        return "x" + reversedString[2] + reversedString[3] + reversedString[0] + reversedString[1];
    }
}
