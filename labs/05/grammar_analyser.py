import sys

def main():
    cfg_file_path = sys.argv[1]
    dict = {}
    cfg_file = open(cfg_file_path, 'r')
    for line in cfg_file:
        line = cleanLine(line)
        dict[line[0]] = {
            'productions': cleanProduction(line[1]),
            'reached': False,
            'isTerminal': False
        }
    cfg_file.close()
    dict = processProductions(dict)
    dict['S']['reached'] = True
    writeFile(dict)

def processProductions(dict):
    values = {}
    for x, y in dict.items():
        print('productions from ', x)
        for prod in y['productions']:
            if isTerminalSymbol(prod):
                dict[x]['isTerminal'] = True
                print(prod)
            elif isSingleVariable(prod):
                dict[prod]['reached'] = True
                print(prod)
            else:
                values = isCombination(prod)
                for value in values['reached']:
                    dict[value]['reached'] = True
    
    return dict

def writeFile(dict):
    for x, y in dict.items():
        if y['reached'] && y['isTerminal']:
            if y[]
def isTerminalSymbol(prod):
    if(len(prod) < 2):
        return prod.islower()
    else:
        lowers = True
        for char in prod:
            if not (char.islower()):
                lowers = False
        return lowers

def isSingleVariable(prod):
    if(len(prod) < 2):
        return not(prod.islower())
    return False

def isCombination(prod):
    values = {
        'reached': []
    }
    for char in prod:
        if not (char.islower()):
            values['reached'].append(char)
    return values
            

def cleanProduction(production):
    productions = production.split('|')
    return productions

def cleanLine(line):
    line = line.replace(' ', '')
    line = line.replace('\n', '')
    line = line.split('-')
    return line

if __name__ == "__main__": main()