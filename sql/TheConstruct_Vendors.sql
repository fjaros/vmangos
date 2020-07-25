replace into creature_template (entry,
patch,
display_id1,
name,subname,
gossip_menu_id,
level_min,level_max,
health_min,health_max,
mana_min,mana_max,
faction,npc_flags,
scale,script_name) values
(2000000,10,15583,'Ahn\'Qiraji Ambassador','Teleporter',0,63,63,1,1,1,1,35,1,2,'npc_go_aq40'),
(2000001,10,15742,'Kurinnaxx','Head',0,63,63,1,1,1,1,35,16388,1,''),
(2000002,10,15345,'The Prophet Skeram','Neck',0,63,63,1,1,1,1,35,16388,1,''),
(2000003,10,15376,'General Rajaxx','Shoulders',0,63,63,1,1,1,1,35,16388,1.1,''),
(2000004,10,15761,'Emperor Vek\'nilash','Back',0,63,63,1,1,1,1,35,16388,1.1,''),
(2000005,10,15509,'Ouro','Chest',0,63,63,1,1,1,1,35,16388,1.5,''),
(2000006,10,15739,'Princess Huhuran','Wrists',0,63,63,1,1,1,1,35,16388,0.8,''),
(2000007,10,15778,'Emperor Vek\'lor','Gloves',0,63,63,1,1,1,1,35,16388,1,''),
(2000008,10,15392,'Moam','Belt',0,63,63,1,1,1,1,35,16388,2,''),
(2000009,10,15432,'Ossirian the Unscarred','Legs',0,63,63,1,1,1,1,35,16388,0.8,''),
(2000010,10,15686,'Viscidus','Feet',0,63,63,1,1,1,1,35,16388,0.4,''),
(2000011,10,15656,'Lord Kri','Rings',0,63,63,1,1,1,1,35,16388,0.65,''),
(2000012,10,15657,'Princess Yauj','Trinkets',0,63,63,1,1,1,1,35,16388,0.65,''),
(2000013,10,15654,'Buru the Gorger','Main Hand',0,63,63,1,1,1,1,35,16388,0.7,''),
(2000014,10,15658,'Vem','Off Hand',0,63,63,1,1,1,1,35,16388,0.65,''),
(2000015,10,15431,'Ayamiss the Hunter','Ranged',0,63,63,1,1,1,1,35,16388,0.8,''),
(2000016,10,15743,'Fankriss the Unyielding','Shields',0,63,63,1,1,1,1,35,16388,1,''),

(2000017,10,15833,'Archmage Magius','Enchantment Mastermind',0,63,63,1,1,1,1,35,16388,1,''),
(2000018,10,11655,'Pico','Speciality Supplies',0,63,63,1,1,1,1,35,16388,1,''),
(2000019,10,2029,'Edwin VanQueef','Poison Supplier',0,63,63,1,1,1,1,35,16388,1,''),
(2000020,10,2618,'Father Buff','Reagents',0,63,63,1,1,1,1,35,16388,1,''),
(2000021,10,12292,'Princess Refrigerator','Food & Drink',0,63,63,1,1,1,1,35,16388,1,''),
(2000022,10,4661,'Witch Doctor Spacey','Bag Vendor',0,63,63,1,1,1,1,35,16388,1,''),
(2000023,10,11660,'Joe Exotic','Mount Vendor',0,63,63,1,1,1,1,35,16388,1,''),

(2000024,10,7919,'The Lich','Chief Alchemyst',0,63,63,1,1,1,1,35,16388,1,''),
(2000025,10,3610,'Needle Haystack','Chief Tailor',0,63,63,1,1,1,1,35,16388,1,''),
(2000026,10,16151,'Vroom Boom','Chief Engineer',0,63,63,1,1,1,1,35,16388,1,''),
(2000027,10,11686,'Flower Shower','Chief Herbalist',0,63,63,1,1,1,1,35,16388,1,''),
(2000028,10,3539,'Vain Thorium','Chief Miner',0,63,63,1,1,1,1,35,16388,1,''),
(2000029,10,8803,'Tinker Binker','Crafter',0,63,63,1,1,1,1,35,16388,1,''),
(2000030,10,14884,'Ivus the NR Lord','',0,63,63,1,1,1,1,35,16388,0.4,'');

-- Combat Dummy
UPDATE creature_template SET level_min=63,level_max=63,health_min=50000,health_max=50000,armor=0,`type`=0,mechanic_immune_mask=8388624,ai_name='',script_name='custom_npc_training_dummy' WHERE entry=1921;

-- Fixed enchanting trainers
replace into gossip_menu_option values
(4153,3,3,'Train me.',3266,5,16,0,0,0,0,0,null,0,0),
(4154,3,3,'Train me.',3266,5,16,0,0,0,0,0,null,0,0),
(4155,3,3,'Train me.',3266,5,16,0,0,0,0,0,null,0,0);
