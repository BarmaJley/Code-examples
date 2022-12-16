package stack;

import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Vadim
 */
public class StackTest {
    
    public StackTest() {
    }
    
    @BeforeClass
    public static void setUpClass(){
    }
    
    @AfterClass
    public static void tearDownClass() {
    }

    /**
     * Test of isEmpty method, of class Stack.
     * @throws Exception
     */
    @Test
    public void testIsEmpty() throws Exception {
        Stack<Integer> s = new Stack<>(10);
        Stack<Integer> emptyS = new Stack<>(10); 
        s.push(1);
        s.push(2);
        s.push(3);
        assertEquals(true, emptyS.isEmpty());
        assertEquals(false, s.isEmpty());

    }

    /**
     * Test of push method, of class Stack.
     * @throws Exception
     */
    @Test
    public void testPush() throws Exception {
        Stack<Integer> s = new Stack<>(10);
        assertEquals(true, s.isEmpty());
        s.push(2);
        s.push(3);
        
        
        assertEquals(false, s.isEmpty());
        assertEquals(10, s.getSize());
        assertEquals(2, s.getTop());
        s.push(4);
        assertEquals(3, s.getTop());
        
    }

    /**
     * Test of pop method, of class Stack.
     * @throws Exception
     */
    @Test
    public void testPop() throws Exception {
        Stack<Integer> s = new Stack<>(10);
        s.push(1);
        s.push(2);
        s.push(3);
        s.pop();
        s.pop();
        s.pop();
        assertEquals(true, s.isEmpty());
    }

    /**
     * Test of peek method, of class Stack.
     * @throws Exception
     */
    @Test
    public void testPeek() throws Exception {
        Stack<Integer> s = new Stack<>(10);
        s.push(1);
        assertEquals(1, s.peek().intValue());
        s.push(2);
        assertEquals(2, s.peek().intValue());
        s.pop();
        assertEquals(1, s.peek().intValue());
    }

    /**
     * Test of getSize method, of class Stack.
     */
    @Test
    public void testGetSize() {
        Stack<Integer> s = new Stack<>(10);
        assertEquals(10, s.getSize());
    }

    /**
     * Test of getTop method, of class Stack.
     * @throws Exception
     */
    @Test
    public void testGetTop() throws Exception {
        Stack<Integer> s = new Stack<>(10); 
        s.push(1);
        s.push(2);
        s.push(3);
        
        assertEquals(3, s.getTop());
        s.pop();
        assertEquals(2, s.getTop());
        s.pop();
        assertEquals(1, s.getTop());
    }

}
