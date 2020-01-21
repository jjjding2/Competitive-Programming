// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   a.cpp                                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: samukano <samukano@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/16 16:29:59 by samukano          #+#    #+#             //
//   Updated: 2018/11/16 16:30:00 by samukano         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

long long sum, n, m, a[211111], cnt, ans, tmp;
int	main()
{
    map <long long, long long> mp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        sum += a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        sum -= a[i];
        mp[a[i]]--;
        if(sum % 2 == 0)
            if(mp[sum / 2] > 0)
                cnt++;
        sum += a[i];
        mp[a[i]]++;
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; ++i)
    {
        sum -= a[i];
        mp[a[i]]--;
        if(sum % 2 == 0)
            if(mp[sum / 2] > 0)
                cout << i + 1 << ' ';
        sum += a[i];
        mp[a[i]]++;
    }
}