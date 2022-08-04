import chardet
import re
import sys
import urllib.parse


# 返回content中从当前index开始的下两个引号"的index
def get_next_two_quota(cur_index: int, content):
    quota1 = content.find("\"", cur_index)
    quota2 = content.find("\"", quota1 + 1)
    return quota1, quota2


# 把八进制转中文
def change_coding(s):
    p = re.compile(r'(?P<s>(\\\d\d\d){3,})')
    for i in p.finditer(s):
        old = i.group('s')
        name = old.split('\\')
        name = ['%x' % int(g, 8) for g in name if g.isdigit()]
        name = '%' + '%'.join(name)
        cn_name = urllib.parse.unquote(name, 'UTF-8')
        return cn_name
    return s


if __name__ == '__main__':
    with open("file") as f:
        content = f.read()
        quota1, quota2 = get_next_two_quota(0, content)
        cn_content = content[0:quota1 + 1]
        while quota1 != -1 and quota2 != -1:
            # 替换两个引号中间的内容
            sub = content[quota1 + 1:quota2]
            cn_sub = change_coding(sub)
            # print(cn_sub)
            cn_content = cn_content + cn_sub
            next_quota1, next_quota2 = get_next_two_quota(quota2 + 1, content)
            if next_quota1 == -1 or next_quota2 == -1:
                break
            cn_content += content[quota2: next_quota1 + 1]
            quota1 = next_quota1
            quota2 = next_quota2
            # print(quota1, quota2)
        cn_content += content[quota2:]
        print(cn_content)
