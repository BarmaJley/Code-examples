package monthdiary;

import java.util.ArrayList;
import java.util.Arrays;



/**
 * Класс реализующий годовой ежедневник
 * @author Vadim
 * @version 1.0
 */
public class MonthDiary {
    /** Константа для обозначения максимального количества дней в месяце */
    final int  MAX_DAY = 31;
    /** Поле номер месяца */
    private int month;
    
    /** Поле количество дней в месяце */
    private int amountOfDays;
    
    /** Поле ежедневный список дел */
    private ArrayList<ArrayList<String>> duties;
    
    /** 
     * Конструктор - создание нового объекта (определенного месяца) 
     * @param month - изначальный месяц ведения дневника
     */
    MonthDiary(int month) {
        // Инициализация номера месяца
        this.month = month;
        
        // Массив с возможным количеством дней в месяце 
        ArrayList<Integer> days = new ArrayList<>(
                Arrays.asList(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31));
        
        // Инициализация количества дней в месяце
        this.amountOfDays = days.get(this.month-1);
        
        // Создание списка дел на месяц
        this.duties = new ArrayList<>(MAX_DAY);
        
        // Инициализация дней в месяце
        for (int i = 0; i < this.amountOfDays; i++)
            duties.add(new ArrayList<>(Arrays.asList()));
    }
    
    /**
    * Функция получения значения поля {@link MonthDiary#month}
    * @return возвращает текущий номер месяца
    */
    public int getMonth(){
        return this.month;
    }
    
    /**
    * Функция получения значения поля {@link MonthDiary#amountOfDays}
    * @return возвращает количество дней текущего месяца
    */
    public int getAmountOfDays(){
        return this.amountOfDays;
    }
    
    public int getAmountOfTasks(int day){
        if (day <= this.amountOfDays)
            return this.duties.get(day-1).size();
        else{
            System.out.println("Такого дня в этом месяце не существует");
            return -1;
        }
    }
    
    /**
    * Функция печати значения поля {@link MonthDiary#duties}
    */
    public void printMonthDuties(){
        for (int i = 0; i < this.amountOfDays-1; i++) { 
            
            System.out.print(i+1);
            System.out.print(duties.get(i));
            System.out.println();
        }  
        System.out.print(this.amountOfDays);
        for (int i=this.amountOfDays-1; i< MAX_DAY; i++){
            
            System.out.print(duties.get(i));
        }    
        System.out.println("");
    }
    
    /**
    * Функция добавления в day новое duty в поле {@link MonthDiary#diary}
    * @param day - день
    * @param duty - дело, которое нужно добавить в день 
    */
    public void add(int day, String duty){
        if (day <= this.amountOfDays)
            this.duties.get(day-1).add(duty);
        else
            System.out.println("Добавить задание на этот день невозможно");
    }
    
    /**
    * Функция печати списка дел в определенный день
    * @param day - день
    */
    public void dump(int day){
        if (day > this.amountOfDays){
            System.out.println("Такой день не существует в данном месяце");
            return;
        }
        ArrayList<String> tasks;
        if (day == this.amountOfDays){
            tasks = new ArrayList<>(Arrays.asList());
            
            for (int i = day-1; i < MAX_DAY; i++)
                if (!this.duties.get(i).isEmpty())
                    tasks.addAll(this.duties.get(i));
                  
        }
        else{
            tasks = this.duties.get(day-1);
        }
        
       
        if ("".equals(tasks.get(0))) System.out.println("Дел нет");
        
        for(String s: tasks){
            System.out.print(s);
            System.out.print("; ");
        }
        System.out.println("");
        
    }
    /**
     * Функция смены месяца на новый {link MonthDiary#month}
     */
    public void next(){
        // Обновление номера месяца
        this.month = this.month + 1;
        if (this.month == 13) this.month = 1; 
        ArrayList<Integer> days = new ArrayList<>(
                Arrays.asList(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31));
        
        //Обновление количества дней в месяце
        this.amountOfDays = days.get(this.month-1);
        
        //Сохранение старых дел
        ArrayList<ArrayList<String>> old_duties = (ArrayList<ArrayList<String>>)this.duties.clone();
       
        //Создание нового списка дел
        this.duties = new ArrayList<>(MAX_DAY);
        
        //Перенос дел из старого расписания в новое
        for (int i = 0; i < old_duties.size(); i++)
            this.duties.add(old_duties.get(i));

    }
    public static void main(String[] args) {
        MonthDiary myDiary = new MonthDiary(1);
        
        myDiary.add(31, "Сделать дз");
        myDiary.add(30, "Убраться");
        myDiary.add(29, "Стоматолог");
        myDiary.add(28, "Магазин");
        myDiary.add(27, "Конференция");
        myDiary.printMonthDuties();
        myDiary.next();
        System.out.println(myDiary.getAmountOfDays());
        myDiary.printMonthDuties();
        myDiary.add(28, "Сделать матан");
        myDiary.dump(28);
        
        
    }
}