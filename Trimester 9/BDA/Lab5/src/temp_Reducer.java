import java.io.IOException;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;
import java.io.IOException;
import java.util.Iterator;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reporter;

public class temp_Reducer extends Reducer <Text,IntWritable,Text,IntWritable> {
    public void reduce(Text key, Iterable <IntWritable> values,Context context)
            throws IOException,InterruptedException {
        int maxvalue = Integer.MIN_VALUE;
        for(IntWritable x: values)
        {
            maxvalue = Math.max(maxvalue, x.get());
        }
        context.write(key, new IntWritable(maxvalue));
    }
}