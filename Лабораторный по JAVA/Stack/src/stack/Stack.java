package stack;

/**
 * Класс реализующий стек на базе массива с элементами типа T
 * @param <T> - тип элементов стека
 * @author Vadim
 * @version 1.0
 */
public class Stack<T> {
    /** Размер стека */
    final private int size;
    
    /** Вершина  стека */
    private int top;
    
    /** Хранилище элементов стека */
    final private T[] stackArr;
    
    public Stack(){
        this.stackArr = null;
        this.size = 0;
        this.top = 0;
    }
    
    /**
     * Конструктор - создание нового объекта
     * @param s - размер стека
     */
    public Stack(int s) {
        this.stackArr = (T[]) new Object[s];
        this.size = s;
        this.top = 0;
    }
    
    /**
     * Функция для роверки на пустоту стека
     * @return - пуст (True) или нет (False) 
     */
    public boolean isEmpty() {
        return top == 0;
    }
    
    /**
     * Функция занесения элемента в стек
     * @param elem - элемент, который добавляется
     * @throws Exception - в случае конца стека
     */
    public void push(T elem) throws Exception {
        if (this.top == this.size) {
            throw new Exception("Выход за границу стека");
        }

        this.stackArr[this.top++] = elem;
    }
    
    /**
     * Функция для удаления вершины стека
     * @return - удаленный элемент
     * @throws Exception 
     */
    public T pop() throws Exception {
        if (this.isEmpty()) {
            throw new Exception("Стек пуст");
        }
        return this.stackArr[--top];
    }

    /**
     * Функция для возвращения значения вершины стека
     * @return - вершина стека
     * @throws Exception  - в случае, если стек - пуст
     */
    public T peek() throws Exception {
        if (this.isEmpty()) {
            throw new Exception("Стек пуст");
        }
        return this.stackArr[top-1];
    }
    
    /**
     * Функция (геттер) для получения вершины стека
     * @return - вершина стека
     */
    public int getTop() {
        return top;
    }
    
    /**
     * Функция (геттер) для получения размера стека
     * @return - размер стека
     */
    public int getSize() {
        return size;
    }
    

    public static void main(String[] args) throws Exception {
        Stack<Integer> s = new Stack<>(50);
        s.push(50);
        s.push(100);
        s.push(150);
        s.push(200);

        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.peek());
        System.out.println(s.pop());
        System.out.println(s.peek());
        System.out.println(s.pop());
        try{
            System.out.println(s.peek());
        } catch(Exception e) {
            System.out.println(e.getMessage());
        }
    }
    
}
