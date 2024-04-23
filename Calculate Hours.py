import math

def difference(h1, m1, h2, m2):
    if h2<h1:
        if m1 == m2:
            t1 = 12 - h1
            h = t1 + h2
            m = 0
            
        elif m2 > m1:
            t1 = 12 - h1
            h = t1 + h2
            m = m2 - m1
        else:
            t1 = 11 - h1
            h = t1 + h2
            s1 = 60 - m1
            m = s1 + m2
    else:
        if m1 == m2:
            h = h2 - h1
            m = 0
        
        elif m2 > m1:
            h = h2 - h1
            m = m2 - m1
        else:
            h = h2 - h1
            s1 = 60 - m1
            m = s1 + m2
    
    print('~%.2d:%.2d' % (h,m))
    return(h,m)
    
if __name__ == "__main__":
    g = True
    while g == True:
        hour = []
        minute = []
        
        print('Monday')
        h1 = int(input('Hour 1 = '))
        m1 = int(input('Minute 1 = '))
        h2 = int(input('Hour 2 = '))
        m2 = int(input('Minute 2 = '))
        print()
        (difference(h1, m1, h2, m2))
        print('*'*6, '\n')

        print('Tuesday')
        th1 = int(input('Hour 1 = '))
        tm1 = int(input('Minute 1 = '))
        th2 = int(input('Hour 2 = '))
        tm2 = int(input('Minute 2 = '))
        print()
        (difference(th1, tm1, th2, tm2))
        print('*'*6, '\n')

        print('Wednesday')
        wh1 = int(input('Hour 1 = '))
        wm1 = int(input('Minute 1 = '))
        wh2 = int(input('Hour 2 = '))
        wm2 = int(input('Minute 2 = '))
        print()
        (difference(wh1, wm1, wh2, wm2))
        print('*'*6, '\n')

        print('Thursday')
        thh1 = int(input('Hour 1 = '))
        thm1 = int(input('Minute 1 = '))
        thh2 = int(input('Hour 2 = '))
        thm2 = int(input('Minute 2 = '))
        print()
        (difference(thh1, thm1, thh2, thm2))
        print('*'*6, '\n')
        
        print('Friday')
        fh1 = int(input('Hour 1 = '))
        fm1 = int(input('Minute 1 = '))
        fh2 = int(input('Hour 2 = '))
        fm2 = int(input('Minute 2 = '))
        print()
        (difference(fh1, fm1, fh2, fm2))
        print('*'*6, '\n')


        print('Times:')
        print('Monday:',end = '')
        m = difference(h1, m1, h2, m2)
        (mhours, mminutes) = m
        hour.append(mhours)
        minute.append(mminutes)

        print('Tuesday:',end = '')
        t = (difference(th1, tm1, th2, tm2))
        (thours, tminutes) = t
        hour.append(thours)
        minute.append(tminutes)

        print('Wednesday:',end = '')
        w = (difference(wh1, wm1, wh2, wm2))
        (whours, wminutes) = w
        hour.append(whours)
        minute.append(wminutes)

        print('Thursday:',end = '')
        th = (difference(thh1, thm1, thh2, thm2))
        (thhours, thminutes) = th
        hour.append(thhours)
        minute.append(thminutes)

        print('Friday:',end = '')
        f = (difference(fh1, fm1, fh2, fm2))
        (fhours, fminutes) = f
        hour.append(fhours)
        minute.append(fminutes)
        
        print()

        h = sum(hour)
        m = sum(minute)

        
        minu = m / 60
        floor = math.floor(minu)
        totalh = h + floor
        minut = minu % 1
        totalm = math.ceil(minut * 60)
        

        print('Total hours:', totalh)
        print('Total minutes:', totalm)
        
        print()

        print('Total {}:{}'.format(totalh, totalm))

        print()

        ask = input('Would you like to calculate more hours (y/n): ')
        if ask == 'y':
            g = True
        else:
            g = False
        
