# for x in range(5, 10):
#    print(x)

# days=["mon", "tue", "wed", "thu", "fri", "sat", "sun"]
# for d in days:
#    print (d)
 
# for x in range(5,10):
#     if (x==7): break
#     if (x % 2 == 0): continue
#     print (x)

# days=["mon", "tue", "wed", "thu", "fri", "sat", "sun"]
# for i,d in enumerate(days):
#     print (i, d)

# fruits = ["apple", "banana", "cherry"]
# for x in fruits:
#   if x == "banana":
#     break
#   print(x)

import asyncio

async def seq():
    print("one")
    await asyncio.sleep(1)
    print("two")

asyncio.run(seq())