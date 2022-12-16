package dictionarysynonyms;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;

public class DictionarySynonyms {
    final private Map<String,HashSet<String>> dictionary;
    
    public DictionarySynonyms() {
        this.dictionary = new HashMap<>();
    }
    
    public DictionarySynonyms(String word1, String word2){
        this.dictionary = new HashMap<>();
        
        HashSet<String> words1 = new HashSet<>();
        HashSet<String> words2 = new HashSet<>();
        this.dictionary.put(word1, words1);
        this.dictionary.get(word1).add(word2);
        this.dictionary.put(word2, words2);
        this.dictionary.get(word2).add(word1);
        
    }
    @Override
    public String toString(){
        return this.dictionary.toString();
    }
    
    
    public void addWord(String word1, String word2){
        HashSet<String> words1 = new HashSet<>();
        HashSet<String> words2 = new HashSet<>();
        
        if (!this.dictionary.containsKey(word1) && !this.dictionary.containsKey(word2)){
            this.dictionary.put(word1, words1);
            this.dictionary.get(word1).add(word2);
            this.dictionary.put(word2, words2);
            this.dictionary.get(word2).add(word1);
        } else
            if (this.dictionary.containsKey(word1) && !this.dictionary.containsKey(word2)){
                this.dictionary.get(word1).add(word2);
                this.dictionary.put(word2, words2);
                this.dictionary.get(word2).add(word1);
            } else 
                if (!this.dictionary.containsKey(word1) && this.dictionary.containsKey(word2)){
                    this.dictionary.get(word2).add(word1);
                    this.dictionary.put(word1, words1);
                    this.dictionary.get(word1).add(word2);
                } else {
                    this.dictionary.get(word1).add(word2);
                    this.dictionary.get(word2).add(word1);
                }  
    }
    
    public int countSynonyms(String word) {
        if (this.dictionary.get(word) == null){
                return -1;
        }
        return this.dictionary.get(word).size();
    }
    
    public void printListSynonyms(String word) {
        if (this.dictionary.get(word) == null){
            System.out.println("Данного слова в словаре нет");
        } else {
            Iterator<String> i = dictionary.get(word).iterator();
            while(i.hasNext()){
                System.out.print(i.next());
                System.out.print(" ");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        DictionarySynonyms dict = new DictionarySynonyms();
        System.out.println(dict.countSynonyms("love"));
        dict.addWord("love", "like");
        System.out.println(dict.countSynonyms("love"));
        System.out.println(dict);
        dict.addWord("love", "adore");
        System.out.println(dict.countSynonyms("love"));
        System.out.println(dict);
        dict.addWord("admire", "like");
        System.out.println(dict);
        dict.addWord("adore", "admire");
        dict.addWord("love", "worship");
        System.out.println(dict.countSynonyms("love"));
        System.out.println(dict);   
        dict.printListSynonyms("love");
    }
    
}
