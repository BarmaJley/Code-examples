package mystream;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Stream;

/**
 *
 * @author Vadim
 */
public class MyStream {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
//        List<Integer> l = new ArrayList<>();
//        Collections.addAll(l, 1, 2, 2, 2, 3,4, 2);
//        
//        for(Integer i: l){
//            System.out.print(i);
//        }
//        
//        System.out.println();
//       
//        //l.stream().filter(x-> x%2 == 0).forEach(x->System.out.print(x));
//       System.out.println(l.stream().count());
//        //l.stream().forEach(x->out.println(x));
//        l.stream();
//        
//        Stream.of("a1", "b2");
//      Сreating stream from array.

        Stream.of("a", "b", "b", "b", "c", "b").forEach(s -> System.out.println("F.e: " + s));
//                .filter(s-> {
//                    return s.startsWith("b");
//                })
//                .map(s -> {
//                    System.out.println("map: "+s);
//                    return s.toUpperCase();
//                })

               
                
    }
    
}
