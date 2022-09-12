class Solution(object):
    def removeOccurrences(self, s, p):
        text = ""

        for c in s:
            text += c
            if len(text) >= len(p) and text[-len(p):] == p:
                text = text[:-len(p)]

        return text
        