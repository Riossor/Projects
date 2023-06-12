

CREATE TABLE administrators (
  username varchar(40) NOT NULL,
  password varchar(40) NOT NULL
);

INSERT INTO administrators VALUES('admin', 'sesame');
INSERT INTO administrators VALUES('joel', 'sesame');

CREATE TABLE customers (
  customerAccount varchar(20) NOT NULL,
  firstName varchar(50) NOT NULL,
  lastName varchar(50) NOT NULL,
  phone varchar(20) NOT NULL,
  email varchar(50) NOT NULL,
  username varchar(50) NOT NULL,
  password varchar(20) NOT NULL
); 

INSERT INTO customers VALUES('13266059', 'Gonzalo', 'Keeton', '(214) 555-3647', '', 'KeetonGonzalo', 'sesame');
INSERT INTO customers VALUES('23398478', 'Marvin', 'Quintin', '(559) 555-9586', 'marvin@expedata.com', 'QuintinMarvin', 'sesame');
INSERT INTO customers VALUES('59086896', 'Marjorie', '', '(800) 555-8110', 'messence@hotmail.com', 'Marjorie', 'sesame');
INSERT INTO customers VALUES('60480105', 'Alexandro', '', '(559) 555-2993', 'alal@yaleindustries.com', 'Alexandro', 'sesame');
INSERT INTO customers VALUES('62224714', 'Derek', 'Chaddick', '(559) 555-3005', 'dChaddick@fresnophoto.com', 'ChaddickDerek', 'sesame');
INSERT INTO customers VALUES('63272365', 'Anton', 'Mauro', '(916) 555-6670', 'amauro@yahoo.org', 'MauroAnton', 'sesame');
INSERT INTO customers VALUES('65064423', 'Ingrid', '', '(201) 555-9742', 'Ingrid@richadvertizing.com', 'Ingrid', 'sesame');
INSERT INTO customers VALUES('71767284', 'Malia', 'Marques', '(314) 555-8834', 'malia@gmail.com', 'MarquesMalia', 'sesame');
INSERT INTO customers VALUES('76410533', 'Emily', 'Evan', '(614) 555-4435', 'Emily@MicroCenter.com', 'EvanEmily', 'sesame');
INSERT INTO customers VALUES('80424490', 'Kendall', 'Mayte', '(559) 555-9999', 'kmayte@fresno.ca.gov', 'MayteKendall', 'sesame');
INSERT INTO customers VALUES('83111068', 'Kaitlyn', 'Anthoni', '(800) 555-6081', 'kanthoni@pge.com', 'AnthoniKaitlyn', 'sesame');
INSERT INTO customers VALUES('83483943', 'Eileen', '', '(770) 555-9558', 'eLawrence@ecomm.com', 'Eileen', 'sesame');
INSERT INTO customers VALUES('91384298', 'Kelly', 'Irvin', '(301) 555-8950', 'kelly@example.com', 'IrvinKelly', 'sesame');
INSERT INTO customers VALUES('99202556', 'Kenzie', 'Quinn', '(800) 555-8725', 'kenzie@jobtrak.com', 'QuinnKenzie', 'sesame');

CREATE TABLE registrations (
  customerAccount varchar(50) NOT NULL,
  vehicleID varchar(10) NOT NULL,
  tireID int(11) NOT NULL
); 

INSERT INTO registrations VALUES('13266059', '11', 93);
INSERT INTO registrations VALUES('23398478', '10', 92);
INSERT INTO registrations VALUES('59086896', '18', 100);
INSERT INTO registrations VALUES('60480105', '15', 97);
INSERT INTO registrations VALUES('62224714', '12', 94);
INSERT INTO registrations VALUES('63272365', '7', 89);
INSERT INTO registrations VALUES('65064423', '16', 98);
INSERT INTO registrations VALUES('71767284', '13', 95);
INSERT INTO registrations VALUES('76410533', '14', 96);
INSERT INTO registrations VALUES('80424490', '9', 91);
INSERT INTO registrations VALUES('83111068', '8', 90);
INSERT INTO registrations VALUES('83483943', '17', 99);
INSERT INTO registrations VALUES('91384298', '5', 87);
INSERT INTO registrations VALUES('99202556', '6', 88);

CREATE TABLE tires (
  tireID int(11) NOT NULL,
  position varchar(20) NOT NULL,
  tireCode varchar(50) NOT NULL,
  name varchar(50) NOT NULL,
  date datetime NOT NULL,
  repaired int(11) NOT NULL
); 

INSERT INTO tires VALUES(87, 'FL', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 0);
INSERT INTO tires VALUES(88, 'RR', '315/40R R20', 'Toyo', '2019-04-28 00:00:00', 1);
INSERT INTO tires VALUES(89, 'FR', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 1);
INSERT INTO tires VALUES(90, 'S', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 1);
INSERT INTO tires VALUES(91, 'RL', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 1);
INSERT INTO tires VALUES(92, 'FL', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 0);
INSERT INTO tires VALUES(93, 'S', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 1);
INSERT INTO tires VALUES(94, 'RR', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 1);
INSERT INTO tires VALUES(95, 'FR', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 2);
INSERT INTO tires VALUES(96, 'S', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 0);
INSERT INTO tires VALUES(97, 'RL', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 1);
INSERT INTO tires VALUES(98, 'FR', '305/35R R20', 'Michellin', '2022-02-28 00:00:00', 0);
INSERT INTO tires VALUES(99, 'S', '245/30R R20', 'Continental', '2017-04-28 00:00:00', 2);
INSERT INTO tires VALUES(100, 'FL', '275/35R R20', 'Continental', '2017-04-28 00:00:00', 2);

CREATE TABLE vehicles (
  vehicleID int(11) NOT NULL,
  vin varchar(50) NOT NULL,
  mileage varchar(18) NOT NULL,
  year varchar(10) NOT NULL,
  make varchar(50) NOT NULL,
  model varchar(50) NOT NULL
); 

INSERT INTO vehicles VALUES(5, '1G8ZH5281YZ265849', '102,444', '2000', 'Saturn', 'S Series');
INSERT INTO vehicles VALUES(6, '3B7KF2363YG116285', '42,104', '2005', 'Dodge', '2500');
INSERT INTO vehicles VALUES(7, '1C4BJWDG8DL559834', '62,564', '2013', 'Jeep', 'Wrangler Unlimited');
INSERT INTO vehicles VALUES(8, 'WA1LKAFP1AA007546', '222,004', '2010', 'Audi', 'Q5');
INSERT INTO vehicles VALUES(9, '1GNKVGED5CJ196120', '82,200', '2012', 'Chevrolet', 'Traverse');
INSERT INTO vehicles VALUES(10, '1GBJK39DX6E165432', '132,689', '2006', 'Chevrolet', 'Silverado 1500');
INSERT INTO vehicles VALUES(11, '2C3CCAFJ2CH801561', '20,488', '2016', 'Chrysler', '300');
INSERT INTO vehicles VALUES(12, '1FTPW125X5FA69245', '220,045', '2005', 'Ford', 'F-150');
INSERT INTO vehicles VALUES(13, 'TRUWT28N011046197', '140,668', '2001', 'Audi', 'TT');
INSERT INTO vehicles VALUES(14, '1GCJK33104F173427', '268,400', '2004', 'Chevrolet', 'Silverado 3500');
INSERT INTO vehicles VALUES(15, 'WAUD2AFD7DN006931', '86,899', '2013', 'Audi', 'S8');
INSERT INTO vehicles VALUES(16, '2C3KA73WX6H237747', '170,069', '2006', 'Chrysler', '300C SRT8');
INSERT INTO vehicles VALUES(17, 'WP0AA29966S716557', '40,733', '2006', 'Porsche', '911');
INSERT INTO vehicles VALUES(18, 'WP1AC29P65LA91996', '90,165', '2005', 'Porsche', 'Cayenne');


ALTER TABLE administrators
  ADD PRIMARY KEY (username);

ALTER TABLE customers
  ADD PRIMARY KEY (customerAccount);

ALTER TABLE registrations
  ADD PRIMARY KEY (customerAccount,vehicleID,tireID);

ALTER TABLE tires
  ADD PRIMARY KEY (tireID);

ALTER TABLE vehicles
  ADD PRIMARY KEY (vehicleID);


ALTER TABLE tires
  MODIFY tireID int(11) NOT NULL AUTO_INCREMENT;

ALTER TABLE vehicles
  MODIFY vehicleID int(11) NOT NULL AUTO_INCREMENT;

GRANT SELECT, INSERT, UPDATE, DELETE
ON *
TO ts_user@localhost
IDENTIFIED BY 'pa55word';

