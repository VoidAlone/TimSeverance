Alright, just a quick tut on how to set up GGD so that drums can be appropriately mapped to different channels on the mixer, and so that we can get the names of the kit pieces to appear properly on the piano roll.

**Note: Piano Roll Keys will be referred to from 0 index. I.e note 22 is the 23nd key starting at 0.**

### Channel Mapping

This is pretty easy. 

Add Kontakt to the channel rack in FL Studio

Once it's open, open up Invasion or whatever your GGD library is.

Select the workspace management key that looks like some boxes up at the top near settings and save. Make sure outputs is selected

Once outputs is visible at the bottom of the kontakt window, hit the + icon, which will open up a "Outputs" dialogue. 

You need to set the number of Outputs you want. For invasion, there's an overhead, room close, room far, and then 16 different instruments from the snares and triggers to the symbols. In total, you'll need 19 outputs, but I went with 20 just to make it even. 

Number of channels: 2 (for stereo)

Host output: st.1 (pick the first one)

Ascending output assignment: Check

Delete existing channels before creating new ones: Check

Make this your default configuration: Check.

Then hit OK.

You should see your outputs at the bottom. Now, in the FL Studio Wrapper, hit the gear, and go to Wrapper Settings > Processing. Click Reset under connections, Set the first output, st1 to channel 1. Then click Auto map outputs.

Back in GGD, click on the Full Kit tab so that the whole kit is visible, and Under the logo, there should be a drop down that says stereo. Under it, click Multi Out ADV. 

Now, when you click kick, snare, etc, you should see that each instrument is properly mapped to an output like st1, st2, st3, etc.

You should now see that each drum maps to a mixer channel when you click on a drum. Now in the Channel Rack, you can decide which channel you want Kontakt on, and each drum piece will be offset by that channel. I set my drums to channel 4, and so all of my pieces are set to 4+...

### Piano Roll Mapping

We're going to use BRSO Articulate to get our Drums properly mapped to the piano roll so it's easy to see what we're doing when programming drums. 

Rather than renaming the piano roll keys manually every time, we're going to create a text file that can be given to BRSO Articulate to do this mapping for us.

For this part, it's a bit complicated, and time consuming, but not too difficult.

The Piano Roll has 132 keys (0-131). On the piano roll, the lowest value, C-2 is index 0, and the highest value, B8 is index 131.

GGD - Invasion has a default mapping spanning from A#-1 (Index 22) to G#4 (Index 80)

You can do this in one of two ways. You can create a text file directly with 132 columns, and then just do the calculation in your head to flip the index for the key to the correct column value (index 0 is column 131, so you'll have to subtract 131 by your index), or you can do some excel magic to make sure you get it right which I think is easier assuming you don't have a direct manual that shows the numeric index for your instrument like GGD.

#### Excel

Set up an excel spreadsheet.

In Column A, Enter Numbers 0-131. 

In Column B, Enter the Notes starting at C-2 through the range of 0-131. I did this by starting at C0 and writing out all 12 notes up to B0. Excel is smart enough to figure out which numbers are next if you select that range and then drag to extend the column. I then backfilled the negative note values.

In Column C, enter the drum pieces that correspond with the notes that they're mapped to in GGD. For instance, Left Kick maps to B-1.

Save your work

Once you have your kit mapped out, you can go to 

Data > Sort 

And then you can sort by Column A, Descending or Greatest to Least.

Save as a new file

Delete your Number and Note Columns.

Now, you'll need to save as a text file.

This is where things get tricky. If you're using libreoffice, there's a way to save the CSV to a text CSV, but excel doesn't seem to offer this option.

If you save your CSV to a text file, and you find that it doesn't have 131 columns, enter as many empty columns as necessary to get your note names to line up with the correct index.

#### BRSO Articulate

Once you have your mapping in a text file, add BRSO to your channel rack. Switch to articulation configuration panel. There will be a piano roll key names option for you to import your txt file. Now, when you open piano roll on BRSO Articulate, you should see the names of your GGD kit on the piano roll.

#### Port mapping

To get sound out of the keys, now we need to just set the midi ports. In my example, I set BRSO Articulate Port to 0, and then I set the input Port for GGD to 0. I didn't mess with Channel in BRSO or Output Port on GGD.

#### Get all of the notes

The last step is to Switch to the General Configuration Panel in BRSO. "Click Muliple Articulate Banks." BRSO only has 16 articulations. This allows you to have multiple banks which gives at least 64. For Invasion Drum Kit, this is enough. For a more complex instrument, you'll likely have to set up multiple BRSO instances, and map to different keys across the piano roll.

