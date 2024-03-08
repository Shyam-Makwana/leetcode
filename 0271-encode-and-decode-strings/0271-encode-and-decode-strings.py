class Solution:
    """
    @param: strs: a list of strings
    @return: encodes a list of strings to a single string.
    """
    def encode(self, strs):
        # write your code here
        n = len(strs)
        encode_list = [""]*n
        for i in range(n):
            encode_list[i] = f"{len(strs[i])}#{strs[i]}"
        return "".join(encode_list)

    """
    @param: str: A string
    @return: decodes a single string to a list of strings
    """
    def decode(self, str):
        # write your code here
        decode_list = []
        i = 0
        while i < len(str):
            word_length = ""
            while str[i] != "#":
                word_length += str[i]
                i += 1
            word_length = int(word_length)
            decode_list.append(str[i+1: i+1+word_length])
            i += word_length + 1

        return decode_list
