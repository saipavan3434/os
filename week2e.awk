BEGIN{
print" record \t character \t words"
}

#BodySection
{
len=length($0)
total_len+=len
print(NR,":\t",len, ":\t",NF,$0)
words+=NF
}

END{
print("\n total")
print("characters:\t" total_len)
print("words :\t" words)
print("lines :\t"NR)
}

