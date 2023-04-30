public static long LongCount<TSource>(this IEnumerable<TSource> source)
{
    if (source == null) throw Error.ArgumentNull("source");
    long count = 0;
    using (IEnumerator<TSource> e = source.GetEnumerator()) {
        checked 
        {
            while (e.MoveNext()) count++;
        }
    }
    return count;
}