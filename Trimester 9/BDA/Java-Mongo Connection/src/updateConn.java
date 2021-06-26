import com.mongodb.BasicDBObject;
import com.mongodb.DBCursor;
import com.mongodb.*;

public class updateConn {
    public static void main(String[] args) {
        MongoClient mongo = new MongoClient("localhost");
        DB db = mongo.getDB("company1");
        DBCollection collection = db.getCollection("stud1");

        BasicDBObject query = new BasicDBObject();
        query.put("Name", "Monika");
        BasicDBObject newDocument = new BasicDBObject();
        newDocument.put("Name", "Yashodhan");
        BasicDBObject updateObj = new BasicDBObject();
        updateObj.put("$set", newDocument);
        collection.update(query, updateObj);
        DBCursor cursor1 = collection.find();
        while (cursor1.hasNext())
        {
            System.out.println(cursor1.next());
        }
    }
}
