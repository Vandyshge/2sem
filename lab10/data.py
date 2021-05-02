import pylab
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.colors import LinearSegmentedColormap
from matplotlib import cm
import numpy as np
import matplotlib.pyplot as plt

def create_data(name_file):
    quan = []
    time = []

    out = open(f'{name_file}.txt', 'r')
    for i in range(6):
        s = out.readline()
        # print(s)
        quan.append(list(map(float, out.readline().strip().split())))
        time.append(list(map(float, out.readline().strip().split())))

    s = out.readline().strip().split()
    # N1 = int(s[2])
    # N2 = int(s[5])
    return (np.array(quan), np.array(time))

def make_grafic(quan, time, name_file, s, apr):
    fig, ax = plt.subplots()
    ax.grid(True)
    # ax.set(xlabel='N', ylabel='t',
    #        title='Полная энергия системы')
    ax.set(xlabel='$(n*0.01)^2$', ylabel='$t*0.01$',
           title='$Асимптотика bubble sort')
    # ax.set(xlabel='$n*log(n)$', ylabel='$t$',
    #         title='$Асимптотика \: сортировок \: за \: O(n*log(n))$')
    name = ['random', 'good', 'bad']
    # name = ['bubble', 'comb', 'selection']
    # name = ['q', 'heap', 'merge']
    color = ['orange', 'green', 'blue']
    # for i in range(len(quan)):
    #     print(quan[i])
    #     print(time[i])
    for i in range(3):
        if apr[i] == '2':
            t = np.array(time[i])*0.01
            n = np.square(np.array(quan[i])*0.01)
        elif apr[i] == 'log':
            t = time[i]
            n = list(map(lambda x: x*np.log2(x), quan[i]))
        elif apr[i] == '1':
            n = quan[i]
            t = time[i]
        print(n, t)
        plt.scatter(n, t, label=name[i], color=color[i], s=25)
        p_1, v_1 = np.polyfit(n, t, deg=1, cov=True)
        p_f1 = np.poly1d(p_1)
        v_f1 = np.poly1d([v_1[0][0], v_1[1][1]])
        plt.plot(n, list(p_f1(n)), color=color[i], label=p_f1)
        print(p_f1)

    # plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left', borderaxespad=0.)
    plt.legend()
    fig.savefig(f'{name_file}_{s}.png')
    plt.show()

def make_grafics(name_file):
    quan, time = create_data(name_file)
    # print(type(quan))
    # for i in range(len(quan)):
    #     print(quan[i])
    #     print(time[i])
    #     print(type(time[i][0]))
    apr1 = ['2', '2', '2']
    # apr1 = ['log', 'log', 'log']
    make_grafic(quan[:3], time[:3], name_file, 'small', apr1)
    make_grafic(quan[3:], time[3:], name_file, 'huge', apr1)


def ex0():
    quan = []
    time = []

    out = open(f'0.txt', 'r')
    for i in range(3):
        s = out.readline()
        # print(s)
        quan.append(list(map(float, out.readline().strip().split())))
        time.append(list(map(float, out.readline().strip().split())))
    out.close()

    apr1 = ['2', '2', '2']
    # apr1 = ['log', 'log', 'log']
    make_grafic(quan, time, 'ex0', 'o(n^2)', apr1)

def ex2():
    quan = []
    time = []

    out = open(f'2.txt', 'r')
    for i in range(3):
        s = out.readline()
        # print(s)
        quan.append(list(map(float, out.readline().strip().split())))
        time.append(list(map(float, out.readline().strip().split())))
    out.close()

    # apr1 = ['2', '2', '2']
    apr1 = ['log', 'log', 'log']
    make_grafic(quan, time, 'ex2', 'O(nlog(n))', apr1)

def ex3():
    quan, time = create_data('3')
    apr = ['2', '2', '2', 'log', 'log', 'log']
    fig, ax = plt.subplots()
    ax.grid(True)
    # ax.set(xlabel='N', ylabel='t',
    #        title='Полная энергия системы')
    ax.set(xlabel='$n$', ylabel='$t$',
           title='Асимптотика разных сортировок на больших массивах')
    # ax.set(xlabel='$n*log(n)$', ylabel='$t$',
    #         title='$Асимптотика \: сортировок \: за \: O(n*log(n))$')
    # name = ['random', 'good', 'bad']
    # name = ['bubble', 'comb', 'selection']
    name = ['bubble', 'comb', 'selection', 'q', 'heap', 'merge']
    color = ['orange', 'green', 'blue', 'red', 'm', 'k']
    # for i in range(len(quan)):
    #     print(quan[i])
    #     print(time[i])
    for i in range(6):
        if apr[i] == '2':
            t = np.array(time[i])*0.01
            n = np.square(np.array(quan[i])*0.01)
        elif apr[i] == 'log':
            t = time[i]
            n = list(map(lambda x: x*np.log2(x), quan[i]))
        elif apr[i] == '1':
            n = quan[i]
            t = time[i]
        print(n, t)
        plt.scatter(n, t, label=name[i], color=color[i], s=25)
        p_1, v_1 = np.polyfit(n, t, deg=1, cov=True)
        p_f1 = np.poly1d(p_1)
        v_f1 = np.poly1d([v_1[0][0], v_1[1][1]])
        plt.plot(n, list(p_f1(n)), color=color[i], label=p_f1)
        print(p_f1)

    # plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left', borderaxespad=0.)
    plt.legend()
    fig.savefig(f'ex3_.png')
    plt.show()

def ex5():
    quan, time = create_data('5')
    apr = ['2', '2', '2', 'log', 'log', 'log']
    fig, ax = plt.subplots()
    ax.grid(True)
    # ax.set(xlabel='N', ylabel='t',
    #        title='Полная энергия системы')
    ax.set(xlabel='$n$', ylabel='$t$',
           title='Асимптотика разных сортировок на маленьких массивах')
    # ax.set(xlabel='$n*log(n)$', ylabel='$t$',
    #         title='$Асимптотика \: сортировок \: за \: O(n*log(n))$')
    # name = ['random', 'good', 'bad']
    # name = ['bubble', 'comb', 'selection']
    name = ['bubble', 'comb', 'selection', 'q', 'heap', 'merge']
    color = ['orange', 'green', 'blue', 'red', 'm', 'k']
    # for i in range(len(quan)):
    #     print(quan[i])
    #     print(time[i])
    for i in range(6):
        if apr[i] == '2':
            t = np.array(time[i])*0.01
            n = np.square(np.array(quan[i])*0.01)
        elif apr[i] == 'log':
            t = time[i]
            n = list(map(lambda x: x*np.log2(x), quan[i]))
        elif apr[i] == '1':
            n = quan[i]
            t = time[i]
        print(n, t)
        plt.scatter(n, t, label=name[i], color=color[i], s=25)
        p_1, v_1 = np.polyfit(n, t, deg=1, cov=True)
        p_f1 = np.poly1d(p_1)
        v_f1 = np.poly1d([v_1[0][0], v_1[1][1]])
        plt.plot(n, list(p_f1(n)), color=color[i], label=p_f1)
        print(p_f1)

    # plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left', borderaxespad=0.)
    plt.legend()
    fig.savefig(f'ex5_.png')
    plt.show()

def ex1():
    quan = []
    time = []

    out = open(f'1.txt', 'r')
    for i in range(4):
        s = out.readline()
        # print(s)
        quan.append(list(map(float, out.readline().strip().split())))
        time.append(list(map(float, out.readline().strip().split())))
    out.close()


    apr = ['2', '2', '2', '2']
    fig, ax = plt.subplots()
    ax.grid(True)
    # ax.set(xlabel='N', ylabel='t',
    #        title='Полная энергия системы')
    ax.set(xlabel='$n^2$', ylabel='$t$',
           title='Асимптотика comb sort при разных флагах')
    # ax.set(xlabel='$n*log(n)$', ylabel='$t$',
    #         title='$Асимптотика \: сортировок \: за \: O(n*log(n))$')
    # name = ['random', 'good', 'bad']
    # name = ['bubble', 'comb', 'selection']
    name = ['-O0', '-O1', '-O2', '-O3']
    color = ['orange', 'green', 'blue', 'm']
    # for i in range(len(quan)):
    #     print(quan[i])
    #     print(time[i])
    for i in range(4):
        if apr[i] == '2':
            t = np.array(time[i])
            n = np.square(np.array(quan[i]))
        elif apr[i] == 'log':
            t = time[i]
            n = list(map(lambda x: x*np.log2(x), quan[i]))
        elif apr[i] == '1':
            n = quan[i]
            t = time[i]
        print(n, t)
        plt.scatter(n, t, label=name[i], color=color[i], s=25)
        p_1, v_1 = np.polyfit(n, t, deg=1, cov=True)
        p_f1 = np.poly1d(p_1)
        v_f1 = np.poly1d([v_1[0][0], v_1[1][1]])
        plt.plot(n, list(p_f1(n)), color=color[i], label=p_f1)
        print(p_f1)

    # plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left', borderaxespad=0.)
    plt.legend()
    fig.savefig(f'ex1.png')
    plt.show()







if __name__ == '__main__':
    # make_grafics('bubble_sort')
    ex1()