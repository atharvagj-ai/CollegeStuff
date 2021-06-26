import java.io.IOException;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class word_Reducer extends Reducer <Text,IntWritable,Text,IntWritable> {
    public void reduce(Text key, Iterable <IntWritable> values,Context context)
            throws IOException,InterruptedException {
        int sum=0;
        for(IntWritable x: values)
        {
            sum+=x.get();
        }
        context.write(key, new IntWritable(sum));
    }
}