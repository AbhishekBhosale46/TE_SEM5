import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.bson.*;

import com.mongodb.MongoClientURI;
import com.mongodb.client.MongoCollection;
import com.mongodb.client.MongoCursor;
import com.mongodb.client.MongoDatabase;
import com.mongodb.MongoClient;


public class Main {
	
	static void listCollections(MongoDatabase db) {
		
		for(String name: db.listCollectionNames()) {
			System.out.println(name);
		}
		System.out.println();
		
	}
	
	static void createCollection( Scanner sc, MongoDatabase db) {
		
		System.out.print("Enter collection name : ");
		String name = sc.next();
		db.createCollection(name);
		System.out.println("Collection created");
		
	}
	
	static void insertIntoCollection(Scanner sc, MongoDatabase db, MongoCollection collection) {
		
		System.out.print("Enter collection name : ");
		String collName = sc.next();
		
		collection = db.getCollection(collName);
		
		System.out.print("Enter no of fields to enter : ");
		int noOfFields = sc.nextInt();
		
		Document doc = new Document();
		while(noOfFields-->0) {
			System.out.print("Enter key and value space separated : ");
			String key = sc.next();
			String value = sc.next();
			doc.append(key, value);
		}
		
		collection.insertOne(doc);
		System.out.println("Data inserted !!");
		
	}
	
	static void readCollection(Scanner sc, MongoDatabase db, MongoCollection collection) {
		
		System.out.print("Enter collection name : ");
		String collName = sc.next();
		
		collection = db.getCollection(collName);
		
		MongoCursor<Document> cur = collection.find().cursor();
		
		while(cur.hasNext()) {
			Document doc = cur.next();
			System.out.println(doc.toJson());
		}
		
	}
	
	

	public static void main(String[] args) {
		
		Logger logger = Logger.getLogger("org.mongodb.driver");
		logger.setLevel(Level.SEVERE);
				
		String username = "31109";
		String pass = "31109";
		String host = "10.10.7.138";
		String connectionString = "mongodb://"+username+":"+pass+"@"+host;
				
		Scanner sc = new Scanner(System.in);
		
		MongoClientURI connUri = new MongoClientURI(connectionString);
		
		MongoClient client = new MongoClient(connUri);
		
		System.out.println("Connected successfully !!");
		
		MongoDatabase db = client.getDatabase("assi12");
		
		MongoCollection collection = null;
		
		createCollection(sc, db);
		listCollections(db);
		insertIntoCollection(sc, db, collection);
		readCollection(sc, db, collection);
		
		
		
	}

}
