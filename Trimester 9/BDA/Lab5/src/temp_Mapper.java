import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class temp_Mapper extends Mapper<LongWritable,Text,Text,IntWritable>
{
    public void map(LongWritable key, Text value, Context context) throws IOException,InterruptedException {
        String line = value.toString();
        String year = line.substring(15,19);
        int temp;
        if(line.charAt(87) == '+') {
            temp = Integer.parseInt(line.substring(88,92));
        }
        else {
            temp = Integer.parseInt(line.substring(87,92));
        }

        String q = line.substring(92,93);
        if (temp != 9999 && q.matches("[01459]"));
        {
            context.write(new Text(year + " Max_temp_valuefor "),new IntWritable(temp));
        }
    }
}