"""
    Hello world `send.py` example implementation using aioamqp.
    See the documentation for more informations.

"""

import asyncio
import aioamqp
import requests
import json
import argparse
from datetime import time
import time
import math

TBS_Index = [0,1,2,3,4,5,6,7,8,9,9,10,11,12,13,14,15,15,16,17,18,19,20,21,22,23,24,25,26]
PRB_TBS_Map = [
{"0":16,"1":24,"2":32,"3":40,"4":48,"5":72,"6":320,"7":104,"8":120,"9":136,"10":152,"11":176,"12":208,"13":232,"14":264,"15":280,"16":320,"17":336,"18":376,"19":408,"20":440,"21":488,"22":520,"23":552,"24":584,"25":616,"26":648},
{"0":32,"1":48,"2":72,"3":104,"4":120,"5":152,"6":176,"7":232,"8":248,"9":296,"10":320,"11":376,"12":440,"13":488,"14":552,"15":600,"16":632,"17":696,"18":776,"19":840,"20":904,"21":1000,"22":1064,"23":1128,"24":1192,"25":1256,"26":1320},
{"0":56,"1":88,"2":120,"3":152,"4":200,"5":232,"6":288,"7":320,"8":392,"9":456,"10":504,"11":584,"12":680,"13":744,"14":840,"15":904,"16":968,"17":1064,"18":1160,"19":1288,"20":1384,"21":1480,"22":1608,"23":1736,"24":1800,"25":1864,"26":1992},
{"0":88,"1":120,"2":160,"3":208,"4":264,"5":320,"6":392,"7":472,"8":536,"9":616,"10":680,"11":776,"12":904,"13":1000,"14":1128,"15":1224,"16":1288,"17":1416,"18":1544,"19":1736,"20":1864,"21":1992,"22":2152,"23":2280,"24":2408,"25":2536,"26":2664},
{"0":120,"1":160,"2":200,"3":272,"4":320,"5":424,"6":504,"7":584,"8":680,"9":776,"10":872,"11":1000,"12":1128,"13":1256,"14":1416,"15":1544,"16":1608,"17":1800,"18":1992,"19":2152,"20":2344,"21":2472,"22":2664,"23":2856,"24":2984,"25":3112,"26":3368},
{"0":152,"1":200,"2":248,"3":320,"4":408,"5":504,"6":600,"7":712,"8":808,"9":936,"10":1032,"11":1192,"12":1352,"13":1544,"14":1736,"15":1800,"16":1928,"17":2152,"18":2344,"19":2600,"20":2792,"21":2984,"22":3240,"23":3496,"24":3624,"25":3752,"26":4008},
{"0":176,"1":232,"2":296,"3":392,"4":488,"5":600,"6":712,"7":840,"8":968,"9":1096,"10":1224,"11":1384,"12":1608,"13":1800,"14":1992,"15":2152,"16":2280,"17":2536,"18":2792,"19":2984,"20":3240,"21":3496,"22":3752,"23":4008,"24":4264,"25":4392,"26":4584},
{"0":200,"1":272,"2":336,"3":440,"4":552,"5":680,"6":808,"7":968,"8":1096,"9":1256,"10":1384,"11":1608,"12":1800,"13":2024,"14":2280,"15":2472,"16":2600,"17":2856,"18":3112,"19":3496,"20":3752,"21":4008,"22":4264,"23":4584,"24":4968,"25":5160,"26":5352},
{"0":232,"1":304,"2":376,"3":504,"4":632,"5":776,"6":936,"7":1096,"8":1256,"9":1416,"10":1544,"11":1800,"12":2024,"13":2280,"14":2600,"15":2728,"16":2984,"17":3240,"18":3624,"19":3880,"20":4136,"21":4584,"22":4776,"23":5160,"24":5544,"25":5736,"26":5992},
{"0":248,"1":344,"2":424,"3":568,"4":696,"5":872,"6":1032,"7":1224,"8":1384,"9":1544,"10":1736,"11":2024,"12":2280,"13":2536,"14":2856,"15":3112,"16":3240,"17":3624,"18":4008,"19":4264,"20":4584,"21":4968,"22":5352,"23":5736,"24":5992,"25":6200,"26":6712},
{"0":288,"1":376,"2":472,"3":616,"4":776,"5":968,"6":1128,"7":1320,"8":1544,"9":1736,"10":1928,"11":2216,"12":2472,"13":2856,"14":3112,"15":3368,"16":3624,"17":4008,"18":4392,"19":4776,"20":5160,"21":5544,"22":5992,"23":6200,"24":6712,"25":6968,"26":7224},
{"0":304,"1":424,"2":520,"3":680,"4":840,"5":1032,"6":1224,"7":1480,"8":1672,"9":1864,"10":2088,"11":2408,"12":2728,"13":3112,"14":3496,"15":3624,"16":3880,"17":4392,"18":4776,"19":5160,"20":5544,"21":5992,"22":6456,"23":6968,"24":7224,"25":7480,"26":7992},
{"0":344,"1":456,"2":568,"3":744,"4":904,"5":1128,"6":1352,"7":1608,"8":1800,"9":2024,"10":2280,"11":2600,"12":2984,"13":3368,"14":3752,"15":4008,"16":4264,"17":4776,"18":5160,"19":5544,"20":5992,"21":6456,"22":6968,"23":7480,"24":7992,"25":8248,"26":8504},
{"0":376,"1":488,"2":616,"3":808,"4":1000,"5":1224,"6":1480,"7":1672,"8":1928,"9":2216,"10":2472,"11":2792,"12":3240,"13":3624,"14":4008,"15":4264,"16":4584,"17":5160,"18":5544,"19":5992,"20":6456,"21":6968,"22":7480,"23":7992,"24":8504,"25":8760,"26":9144},
{"0":392,"1":520,"2":648,"3":872,"4":1064,"5":1320,"6":1544,"7":1800,"8":2088,"9":2344,"10":2664,"11":2984,"12":3368,"13":3880,"14":4264,"15":4584,"16":4968,"17":5352,"18":5992,"19":6456,"20":6968,"21":7480,"22":7992,"23":8504,"24":9144,"25":9528,"26":9912},
{"0":424,"1":568,"2":696,"3":904,"4":1128,"5":1384,"6":1672,"7":1928,"8":2216,"9":2536,"10":2792,"11":3240,"12":3624,"13":4136,"14":4584,"15":4968,"16":5160,"17":5736,"18":6200,"19":6968,"20":7480,"21":7992,"22":8504,"23":9144,"24":9912,"25":10296,"26":10680},
{"0":456,"1":600,"2":744,"3":968,"4":1192,"5":1480,"6":1736,"7":2088,"8":2344,"9":2664,"10":2984,"11":3496,"12":3880,"13":4392,"14":4968,"15":5160,"16":5544,"17":6200,"18":6712,"19":7224,"20":7992,"21":8504,"22":9144,"23":9912,"24":10296,"25":10680,"26":11448},
{"0":488,"1":632,"2":776,"3":1032,"4":1288,"5":1544,"6":1864,"7":2216,"8":2536,"9":2856,"10":3112,"11":3624,"12":4136,"13":4584,"14":5160,"15":5544,"16":5992,"17":6456,"18":7224,"19":7736,"20":8248,"21":9144,"22":9528,"23":10296,"24":11064,"25":11448,"26":11832},
{"0":504,"1":680,"2":840,"3":1096,"4":1352,"5":1672,"6":1992,"7":2344,"8":2664,"9":2984,"10":3368,"11":3880,"12":4392,"13":4968,"14":5544,"15":5736,"16":6200,"17":6712,"18":7480,"19":8248,"20":8760,"21":9528,"22":10296,"23":11064,"24":11448,"25":12216,"26":12576},
{"0":536,"1":712,"2":872,"3":1160,"4":1416,"5":1736,"6":2088,"7":2472,"8":2792,"9":3112,"10":3496,"11":4008,"12":4584,"13":5160,"14":5736,"15":6200,"16":6456,"17":7224,"18":7992,"19":8504,"20":9144,"21":9912,"22":10680,"23":11448,"24":12216,"25":12576,"26":12960},
{"0":568,"1":744,"2":936,"3":1224,"4":1480,"5":1864,"6":2216,"7":2536,"8":2984,"9":3368,"10":3752,"11":4264,"12":4776,"13":5352,"14":5992,"15":6456,"16":6712,"17":7480,"18":8248,"19":9144,"20":9912,"21":10680,"22":11448,"23":12216,"24":12960,"25":13536,"26":14112},
{"0":600,"1":776,"2":968,"3":1256,"4":1544,"5":1928,"6":2280,"7":2664,"8":3112,"9":3496,"10":3880,"11":4392,"12":4968,"13":5736,"14":6200,"15":6712,"16":7224,"17":7992,"18":8760,"19":9528,"20":10296,"21":11064,"22":11832,"23":12576,"24":13536,"25":14112,"26":14688},
{"0":616,"1":808,"2":1000,"3":1320,"4":1608,"5":2024,"6":2408,"7":2792,"8":3240,"9":3624,"10":4008,"11":4584,"12":5352,"13":5992,"14":6456,"15":6968,"16":7480,"17":8248,"18":9144,"19":9912,"20":10680,"21":11448,"22":12576,"23":12960,"24":14112,"25":14688,"26":15264},
{"0":648,"1":872,"2":1064,"3":1384,"4":1736,"5":2088,"6":2472,"7":2984,"8":3368,"9":3752,"10":4264,"11":4776,"12":5544,"13":6200,"14":6968,"15":7224,"16":7736,"17":8760,"18":9528,"19":10296,"20":11064,"21":12216,"22":12960,"23":13536,"24":14688,"25":15264,"26":15840},
{"0":680,"1":904,"2":1096,"3":1416,"4":1800,"5":2216,"6":2600,"7":3112,"8":3496,"9":4008,"10":4392,"11":4968,"12":5736,"13":6456,"14":7224,"15":7736,"16":7992,"17":9144,"18":9912,"19":10680,"20":11448,"21":12576,"22":13536,"23":14112,"24":15264,"25":15840,"26":16416},
{"0":712,"1":936,"2":1160,"3":1480,"4":1864,"5":2280,"6":2728,"7":3240,"8":3624,"9":4136,"10":4584,"11":5352,"12":5992,"13":6712,"14":7480,"15":7992,"16":8504,"17":9528,"18":10296,"19":11064,"20":12216,"21":12960,"22":14112,"23":14688,"24":15840,"25":16416,"26":16992},
{"0":744,"1":968,"2":1192,"3":1544,"4":1928,"5":2344,"6":2792,"7":3368,"8":3752,"9":4264,"10":4776,"11":5544,"12":6200,"13":6968,"14":7736,"15":8248,"16":8760,"17":9912,"18":10680,"19":11448,"20":12576,"21":13536,"22":14688,"23":15264,"24":16416,"25":16992,"26":17568},
{"0":776,"1":1000,"2":1256,"3":1608,"4":1992,"5":2472,"6":2984,"7":3368,"8":3880,"9":4392,"10":4968,"11":5736,"12":6456,"13":7224,"14":7992,"15":8504,"16":9144,"17":10296,"18":11064,"19":12216,"20":12960,"21":14112,"22":15264,"23":15840,"24":16992,"25":17568,"26":18336},
{"0":776,"1":1032,"2":1288,"3":1672,"4":2088,"5":2536,"6":2984,"7":3496,"8":4008,"9":4584,"10":5160,"11":5992,"12":6712,"13":7480,"14":8248,"15":8760,"16":9528,"17":10296,"18":11448,"19":12576,"20":13536,"21":14688,"22":15840,"23":16416,"24":17568,"25":18336,"26":19080},
{"0":808,"1":1064,"2":1320,"3":1736,"4":2152,"5":2664,"6":3112,"7":3624,"8":4264,"9":4776,"10":5352,"11":5992,"12":6712,"13":7736,"14":8504,"15":9144,"16":9912,"17":10680,"18":11832,"19":12960,"20":14112,"21":15264,"22":16416,"23":16992,"24":18336,"25":19080,"26":19848}
]

#parser = argparse.ArgumentParser()
#parser.add_argument("--rnti","-r",help="RNTI of the UE",required=True)
#args = parser.parse_args()
def get_ue_info():
    #URL="https://httpbin.org/get"
    URL="http://127.0.0.1:9999/stats/"
    r = requests.get(url = URL)
    data = r.json()
    time.sleep(0.1)
    return data
    
async def send():
    transport, protocol = await aioamqp.connect(host='localhost')
    channel = await protocol.channel()
    i=0
    await channel.queue_declare(queue_name='hello')
    while 1:
        obj = get_ue_info()
        txq = 0
        dlcqi = 0
        tbsDL = 0
        prbDL = 0
        if len(obj)>1:
            test = obj['eNB_config'][0]['eNB']['cellConfig'][0]['dlBandwidth']
            print(test)
            cellPRB = obj['eNB_config'][0]['eNB']['cellConfig'][0]['dlBandwidth']
            mac = obj['mac_stats'][0]['ue_mac_stats']
            usedPRB = 0
            PrbUE = 0
            TbsUE = 0
            McsUE = 0
            CqiUE = 0
            nUEs = len(mac)
            for i in range(nUEs):
                usedPRB += mac[i]['mac_stats']['macStats']['prbDl']
                if i == 0 :
                    PrbUE = mac[i]['mac_stats']['macStats']['prbDl']
                    TbsUE = mac[i]['mac_stats']['macStats']['tbsDl']
                    McsUE = mac[i]['mac_stats']['macStats']['mcs1Dl']
                    CqiUE = mac[i]['mac_stats']['dlCqiReport']['csiReport'][0]['p10csi']['wbCqi']
            FreePRB = (cellPRB - usedPRB) + PrbUE
            TbsDL = TbsUE
            if ((FreePRB > 0) and (FreePRB <= len(PRB_TBS_Map))):
                TbsDL = math.ceil((PRB_TBS_Map[FreePRB-1][str(TBS_Index[min(McsUE,28)])])/8)
                #dlcqi = obj['mac_stats']['dlCqiReport']['csiReport'][0]['p10csi']['wbCqi']
                #tbsDL = obj['mac_stats']['macStats']['tbsDl']
                #prbDL = obj['mac_stats']['macStats']['prbDl']
                print ("[dlCQI]={},[txQ]={},[tbsDL]={},[prbDL]={},[cellPRB]={},[PRBu]={},[TBSu]={}".format(CqiUE,0,TbsDL,FreePRB,cellPRB,PrbUE,TbsUE))
                channel_info = str(CqiUE)+","+str(0)+","+str(TbsDL)+","+str(PrbUE)
                await channel.basic_publish(payload=channel_info,exchange_name='',routing_key='hello')
    await protocol.close()
    transport.close()
            
asyncio.get_event_loop().run_until_complete(send())
#send()