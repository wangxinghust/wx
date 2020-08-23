import java.util.LinkedList;
import java.util.Queue;

/**
 * 思路一即上述方法，两个队列，pop的时候弹出至最后一个，注意top值的设置，保障了top值返回不用遍历
 */
class MyStack {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;
    private int top;

    /**
     * Initialize your data structure here.
     */
    public MyStack() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        queue1.add(x);
        top = x;
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        while (queue1.size() > 1) {
            // 弹出时还需更改top值，使其为倒数第二个的值，在循环里反复更新可得
            top = queue1.remove();
            queue2.add(top);
        }
        int res = queue1.remove();
        Queue<Integer> tmp = queue1;
        queue1 = queue2;
        queue2 = tmp;
        return res;
    }

    /**
     * Get the top element.
     */
    public int top() {
        return top;
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return queue1.isEmpty();
    }
}

/**
 * @author Wang Xing
 * @date 8/23/20
 */
public class ImplementStackUsingQueues {
    public static void main(String[] args) {
        MyStack stack = new MyStack();

        stack.push(1);
        stack.push(2);
        stack.pop();
        stack.top();
        stack.empty();
    }
}

/**
 * 思路二是略难理解，是保持q1本身就是个stack，q2里push一个后，把q1的重新灌进q2，调换，从而继续保持q1是stack
 */
class MyStack2 {

    private Queue<Integer> q1 = new LinkedList<>();
    private Queue<Integer> q2 = new LinkedList<>();
    private int top;

    /**
     * Initialize your data structure here.
     */
    public MyStack2() {

    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        q2.add(x);
        top = x;
        while (!q1.isEmpty()) {
            q2.add(q1.remove());
        }
        Queue<Integer> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        int res = q1.remove();
        if (!q1.isEmpty()) {
            top = q1.peek();
        }
        return res;
    }

    /**
     * Get the top element.
     */
    public int top() {
        return top;
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return q1.isEmpty();
    }
}

/**
 * 思路三即保持q1本身就是个stack，在rear处插入新值，则将前面的值重新扔到新值的后面，使插入的值成为queue的front，即stack的top
 */
class MyStack3 {

    private LinkedList<Integer> q1 = new LinkedList<>();

    /**
     * Initialize your data structure here.
     */
    public MyStack3() {

    }

    /**
     * Push element x onto stack.
     */
    public void push(int x) {
        q1.add(x);
        int sz = q1.size();
        while (sz > 1) {
            q1.add(q1.remove());
            sz--;
        }
    }

    /**
     * Removes the element on top of the stack and returns that element.
     */
    public int pop() {
        return q1.remove();
    }

    /**
     * Get the top element.
     */
    public int top() {
        return q1.peek();
    }

    /**
     * Returns whether the stack is empty.
     */
    public boolean empty() {
        return q1.isEmpty();
    }
}
