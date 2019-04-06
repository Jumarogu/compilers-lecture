import sys

current_line = []
current_word = 0 
dt = {'S': []}
f = open("graph.txt", "w")


def main():
    global current_line
    global dt
    global f
    cfg_file_path = sys.argv[1]
    cfg_file = open(cfg_file_path, 'r')
    for line in cfg_file:
        line = cleanLine(line)
        if ((line !=  '\n') & (line != '')):
            dt = {'S': []}
            current_line = line.split(' ')
            #current_line.remove('')
            print(current_line)
            if(len(current_line)):
                if (matchS()):
                    genGrap()
    cfg_file.close()
    f.close()

def genGrap():
    global dt
    global f
    for gen in dt:
        line = '{} '.format(gen)
        for stop in dt[gen]:
            print(stop)
            stopText = '-> ' + stop
            line = line + stopText
        f.write(line + '\n')
    f.write('\n')

def matchS():
    global dt
    if (matchA()):
        dt['S'].append('{A}')
    elif matchD():
        dt['S'].append('{D}')
    return matchA() | matchD()

def matchA():
    global dt
    global current_line
    if ((current_line[0] == 'id') & (current_line[1] == 'assign')):
        dt['A'] = ['{id, assign, V, O}']
        return matchV(2) & matchO(3)
    return False

def matchD():
    global dt
    global current_line
    if (current_line[0] == 'print'):
        dt['D'] = ['{print, id}']
        return True
    elif (current_line[0] == 'intdcl'):
        dt['D'] = ['{intdcl, id}']
        return True
    elif (current_line[0] == 'floatdcl'):
        dt['D'] = ['{floatdcl, id}']
        return True
    return False

def matchO(index):
    global dt
    global current_line
    if(len(current_line) > index):
        if(current_line[index] == 'minus'):
            dt['O'] = ['{minus, V, O}']
        elif(current_line[index] == 'plus'):
            dt['O'] = ['{plus, V, O}']
        elif(current_line[index] == 'multiplication'):
            dt['O'] = ['{multiplication, V, O}']
        elif(current_line[index] == 'division'):
            dt['O'] = ['{division, V, O}']
        elif(current_line[index] == '@'):
            dt['O'] = ['{@}']
            return True
        return matchV(index + 1) & matchO(index + 2)
    return False

def matchV(index):
    global dt
    global current_line
    if(len(current_line) > index):
        if(current_line[index] == 'id'):
            dt['V'] = ['{id}']
            return True
        elif(current_line[index] == 'inum'):
            dt['V'] = ['{inum}']
            return True
        elif(current_line[index] == 'fnum'):
            dt['V'] = ['{fnum}']
            return True
        return False
    return False

def cleanLine(line):
    line = line.replace('\n', '')
    if (line == 'comment'):
        line = line.replace('comment','')
    line = line.replace('\n', '')
    return line

if __name__ == "__main__": main()