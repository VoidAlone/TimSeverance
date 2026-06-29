In general with Blueprint Native Events, when you call the base function, so in your case HandleSomething from C++, it will automatically call the Implementation, but first it will try to call the implementation that’s overridden inside your blueprints, so you don’t have to call that yourself. If you ever do want to add logic to your blueprint overridden native event, just add your logic, but remember to call the parent function, which will run the C++ code

My example:  

[![image](https://d3kjluh73b9h9o.cloudfront.net/optimized/4X/9/2/8/928e06e87c1f98342a7404b4f30c79c8f3cb0f3d_2_690x59.png)

image1036×90 30.9 KB

](https://d3kjluh73b9h9o.cloudfront.net/original/4X/9/2/8/928e06e87c1f98342a7404b4f30c79c8f3cb0f3d.png "image")

[![image](https://d3kjluh73b9h9o.cloudfront.net/optimized/4X/a/c/f/acfff5bcc18329a4ec89321bd91063e5efbf7c80_2_690x72.png)

image996×104 16.4 KB

](https://d3kjluh73b9h9o.cloudfront.net/original/4X/a/c/f/acfff5bcc18329a4ec89321bd91063e5efbf7c80.png "image")

And just for showing how it would work, if I override it in BP:  

[![image](https://d3kjluh73b9h9o.cloudfront.net/original/4X/2/e/d/2ed085262a8210ddab1705be7c1837c535ea3d23.png)

image735×202 10.5 KB

](https://d3kjluh73b9h9o.cloudfront.net/original/4X/2/e/d/2ed085262a8210ddab1705be7c1837c535ea3d23.png "image")

The parent node is basically the C++ code. When I call OnDamageReceived from C++, it will find the function if it’s overridden in BP, and call that first ignoring the C++ code, unless I call the parent function inside the BP

if I’m not mistaken, not overriding your function in BP will cause an infinite loop, because calling HandleSomthing will first search in the BP to run that implementation, but if that doesn’t exist then it will run the _Implementation C++ function, which calls itself in its body thus creating a loop, and crashing

So to sum up:

- Blueprint native events will call the Blueprint function first, if it exists. Unreal handles that automatically
- Never call the _Implementation directly, unless in the form of Super::Something_Implementation() inside the body of a C++ overridden implementation
- Treat the native event as any other function, which means that inheritance works the same way. If you override a Native Event in blueprint, the C++ function is the “Super”, or in BP language the parent. If you override the event in an inheriting blueprint, then you once again need to call the parent if that’s what you need. The parent in that case would be the parent blueprint event implementation

Source: zeaf - https://forums.unrealengine.com/t/blueprintnativeevent-crash-what-am-i-doing-wrong/606192/2