import com.mongodb.*;

public class MongoJavaConn {
    public static void main(String[] args) {
        MongoClient mongo = new MongoClient("localhost");
        DB db = mongo.getDB("company1");
        DBCollection collection = db.getCollection("stud1");

        BasicDBObject d1 = new BasicDBObject("rollno", "1")
                .append("Name",  "Monika")
                .append("Age", "18");
        BasicDBObject d2 = new BasicDBObject("rollno", "2")
                .append("Name",  "Mike")
                .append("Age", "20");
        BasicDBObject d3 = new BasicDBObject("rollno", "3")
                .append("Name",  "James")
                .append("Age", "20");
        collection.insert(d1);
        collection.insert(d2);
        collection.insert(d3);
        System.out.println("Document inserted Successfully");
        //Display Document
        DBCursor cursor = collection.find();
        while (cursor.hasNext())
        {
            System.out.println(cursor.next());
        }
    }
}
