import com.mongodb.*;

public class removeConn {
    public static void main(String[] args) {
        MongoClient mongo = new MongoClient("localhost");
        DB db = mongo.getDB("company1");
        DBCollection collection = db.getCollection("stud1");

        BasicDBObject searchQuery = new  BasicDBObject();
        searchQuery.put("Name", "Yashodhan");
        collection.remove(searchQuery);

        System.out.println("Document removed Successfully");


    }
}
