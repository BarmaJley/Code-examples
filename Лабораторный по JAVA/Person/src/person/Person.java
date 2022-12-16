
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;


public class Person {
    private HashMap<Integer, String[]> info;

    public Person() {this.info = new HashMap<>();}

    // добавить факт изменения имени на first_name в год year
    void changeFirstName(int year, String first_name) {
        if (this.info.containsKey(year)) this.info.get(year)[0] = first_name;
        else this.info.put(year, new String[]{first_name, ""});
    }

    void changeLastName(int year, String last_name) {
        if (this.info.containsKey(year)) this.info.get(year)[1] = last_name;
        else this.info.put(year, new String[]{"", last_name});
    }
     String getFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        String res = "";

        if (info.containsKey(year)) {
            if (info.get(year)[0] == "") {
                ArrayList<Integer> _keys = new ArrayList<>();
                for(Integer k : info.keySet()) {
                    _keys.add(Integer.valueOf(k));
                }
                Collections.sort(_keys);
 
                int index = 0;
                while (index < _keys.size()-1 && _keys.get(index+1) < year) {
                    index++;
                }
 
                while (index >= 0 && info.get(_keys.get(index))[0] == "") {
                    index--;
                }
 
 
                if (index == -1)
                    res += info.get(year)[1] + " with unknown first name";
                else {
                    res += info.get(_keys.get(index))[0] +  " " + info.get(year)[1];
                }
            }
            else if (info.get(year)[1] == "") {
                ArrayList<Integer> _keys = new ArrayList<>();
                for(Integer k : info.keySet()) {
                    _keys.add(Integer.valueOf(k));
                }
                Collections.sort(_keys);
 
                int index = 0;
                while (index < _keys.size()-1 && _keys.get(index+1) < year) {
                    index++;
                }
 
                while (index >= 0 && info.get(_keys.get(index))[1] == "") {
                    index--;
                }
 
 
                if (index == -1)
                    res += info.get(year)[0] + " with unknown second name";
                else {
                    res += info.get(year)[0] + " " + info.get(_keys.get(index))[1];
                }
            }
            else {
                res += info.get(year)[0] + " " + info.get(year)[1];
            }
        }
        else {
            if (info.isEmpty())
                res += "Incognito";
            else {
                String sSecond = "";
                String sFirst = "";
 
                ArrayList<Integer> _keys = new ArrayList<>();
                for(Integer k : info.keySet()) {
                    _keys.add(Integer.valueOf(k));
                }
                Collections.sort(_keys);
 
                int index = 0;
                while (index < _keys.size()-1 && _keys.get(index+1) < year) {
                    index++;
                }
 
                while (index >= 0 && info.get(_keys.get(index))[1] == "") {
                    index--;
                }
 
 
                if (index != -1)
                    sSecond += info.get(_keys.get(index))[1];
 
                index = 0;
                while (index < _keys.size()-1 && _keys.get(index+1) < year) {
                    index++;
                }
 
                while (index >= 0 && info.get(_keys.get(index))[0] == "") {
                    index--;
                }
 
 
                if (index != -1)
                    sFirst += info.get(_keys.get(index))[0];
 
                boolean flag = false;
                if (sFirst == "") {
                    sFirst += "with unknown first name";
                    flag = true;
                }
 
                if (sSecond == "")
                    sSecond += "with unknown second name";
 
                if (!flag)
                    res += sFirst + " " + sSecond;
                else
                    res += sSecond + " " + sFirst;
 
            }
        }
 
        return res;
    }


    
    String getFullNameWithHistory(int year) {
        // получить все имена и фамилии по состоянию на конец года year
        String res = "";
 
        ArrayList<Integer> _keys = new ArrayList<>();
        for(Integer k : info.keySet()) {
            _keys.add(Integer.valueOf(k));
        }
 
        Collections.sort(_keys);
        res += this.getFullName(year);
 
        if (_keys.size() > 0 && _keys.get(0) <= year) {
            int index = 0;
            while (index < _keys.size() && _keys.get(index) < year) {
                index++;
            }
 
            if (index != 0)
                res += " (";
            index--;
            while (index > 0) {
                res += this.getFullName(_keys.get(index)) + ", ";
                index--;
            }
            if (index == 0)
                res += this.getFullName(_keys.get(0)) + ") ";
        }
        return res;
    }

    public static void main(String[] args) {
        Person p = new Person();

        System.out.println(p.getFullName(2020));
        System.out.println(p.getFullNameWithHistory(2020));
        System.out.println();
 
        p.changeFirstName(2019, "Vadim");
        System.out.println(p.getFullName(2020));
        System.out.println(p.getFullNameWithHistory(2020));
        System.out.println();
 
        p.changeFirstName(2017, "Vlad");
        System.out.println(p.getFullName(2020));
        System.out.println(p.getFullNameWithHistory(2020));
        System.out.println();
 
        p.changeLastName(2018, "Chaikin");
        System.out.println(p.getFullName(2020));
        System.out.println(p.getFullNameWithHistory(2020));
        System.out.println();
 
        p.changeLastName(2005, "Baiden");
        System.out.println(p.getFullName(2006));
        System.out.println(p.getFullNameWithHistory(2006));
        System.out.println();
        
        
        System.out.println(p.getFullName(2018));
        System.out.println(p.getFullNameWithHistory(2018));
        System.out.println();
    }
}
