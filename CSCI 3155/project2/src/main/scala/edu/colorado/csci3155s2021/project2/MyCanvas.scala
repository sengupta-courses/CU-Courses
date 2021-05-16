package edu.colorado.csci3155s2021.project2

/* A class to maintain a canvas */
import java.awt.geom.{Ellipse2D, Rectangle2D}
import java.awt.{Graphics2D}

/* A figure is a sealed trait. It can be a Polygon or a "MyCircle"*/
sealed trait Figure {
    def getBoundingBox: (Double, Double, Double, Double)
    def translate(x: Double, y: Double): Figure
    def rotate(angRad: Double, x:Double, y:Double): Figure
    def render(g: Graphics2D, scaleX: Double, scaleY: Double, shiftX: Double, shiftY: Double): Unit
}

/*
 Class Polygon
   A polygon is defined by a list of its vertices
 */
case class Polygon(val cList: List[(Double, Double)]) extends Figure {

    //TODO: Define the bounding box of the polygon
    // This function returns a 4-tuple (xmin, xmax, ymin, ymax)
    override def getBoundingBox: (Double, Double, Double, Double ) = {
        val d1 = cList.map(_._1).min
        val d2 = cList.map(_._1).max
        val d3 = cList.map(_._2).min
        val d4 = cList.map(_._2).max

        (d1, d2, d3, d4)
    }

    //TODO: Create a new polygon by shifting each vertex in cList by (x,y)
    //    Do not change the order in which the vertices appear
    override def translate(x: Double, y: Double): Polygon = {
        val mapL = cList.map{
            case (a,b) => (a + x, b + y)
        }

        new Polygon(mapL)
    }

    override def rotate(angRad:Double, x:Double, y:Double): Polygon = {
        val cosT = scala.math.cos(angRad)
        val sinT = scala.math.sin(angRad)

        val newP = cList.map {
            case (a, b) => (a - x, b - y)
        };
        Polygon(newP.map{
            case(a, b) => ((a) * cosT - (b) * sinT, (a) * sinT + (b) * cosT)
        }).translate(x, y)

    }


    // Function: render -- draw the polygon. Do not edit this function.
    override def render(g: Graphics2D, scaleX: Double, scaleY: Double, shiftX: Double, shiftY: Double) = {
        val xPoints: Array[Int] = new Array[Int](cList.length)
        val yPoints: Array[Int] = new Array[Int](cList.length)
        for (i <- 0 until cList.length){
            xPoints(i) = ((cList(i)._1 + shiftX )* scaleX).toInt
            yPoints(i) = ((cList(i)._2 + shiftY) * scaleY).toInt
        }
        g.drawPolygon(xPoints, yPoints, cList.length)

    }
}

/*
  Class MyCircle
  Define a circle with a given center c and radius r
 */
case class MyCircle(val c: (Double, Double), val r: Double) extends Figure {
    //TODO: Define the bounding box for the circle
    override def getBoundingBox: (Double, Double, Double, Double) = {
        val c1 = c._1 - r
        val c2 = c._1 + r
        val c3 = c._2 - r
        val c4 = c._2 + r

        (c1, c2, c3, c4)
    }


    //TODO: Create a new circle by shifting the center
    override def translate(x: Double, y: Double): MyCircle = {
        val cx = c._1 + x
        val cy = c._2 + y

        new MyCircle((cx, cy), r)
    }

    override def rotate(angRad:Double, x: Double, y: Double): MyCircle = {
        val newC = translate(-x, -y)
        val cosT = scala.math.cos(angRad)
        val sinT = scala.math.sin(angRad)
        new MyCircle((newC.c._1 * cosT - newC.c._2 * sinT, newC.c._1 * sinT + newC.c._2 * cosT), r)
    }

    // Function: render -- draw the circle. Do not edit this function
    override def render(g: Graphics2D, scaleX: Double, scaleY: Double, shiftX: Double, shiftY: Double) = {
        val centerX = ((c._1 + shiftX) * scaleX) .toInt
        val centerY = ((c._2 + shiftY) * scaleY) .toInt
        val radX = (r * scaleX).toInt
        val radY = (r * math.abs(scaleY)).toInt
        //g.draw(new Ellipse2D.Double(centerX, centerY, radX, radY))
        g.drawOval(centerX-radX, centerY-radY, 2*radX, 2*radY)
    }
}

/*
  Class : MyCanvas
  Define a canvas through a list of figure objects. Figure objects can be circles or polygons.
 */

class MyCanvas (val listOfObjects: List[Figure]) {

    // TODO: Write a function to get the boundingbox for the entire canvas.
    // Hint: use existing boundingbox functions defined in each figure.
    def getBoundingBox: (Double, Double, Double, Double) = {
        val m1 = listOfObjects.map(_.getBoundingBox._1).min
        val m2 = listOfObjects.map(_.getBoundingBox._2).max
        val m3 = listOfObjects.map(_.getBoundingBox._3).min
        val m4 = listOfObjects.map(_.getBoundingBox._4).max

        (m1, m2, m3, m4)
    }

    //TODO: Write a function to translate each figure in the canvas by shiftX, shiftY
    def translate(shiftX: Double, shiftY: Double): MyCanvas = {
        new MyCanvas(listOfObjects.map(_.translate(shiftX, shiftY)))
    }

    //TODO: Write a function that will return a new MyCanvas object that places
    // all the objects in myc2 to the right of the objects in this MyCanvas.
    // refer to the notebook documentation on how to perform this.
    def placeRight(myc2: MyCanvas):MyCanvas = {
        val shiftX = getBoundingBox._2 - myc2.getBoundingBox._1
        val shiftY = ((getBoundingBox._4 - getBoundingBox._3) / 2) - ((myc2.getBoundingBox._4 - myc2.getBoundingBox._3) / 2)

        overlap(myc2.translate(shiftX, shiftY))

    }
    //TODO: Write a function that will return a new MyCanvas object that places
    // all the figures in myc2 on top of the figures in this MyCanvas.
    // refer to the notebook documentation on how to perform this.
    def placeTop(myc2: MyCanvas): MyCanvas = {
        val shiftX = ((getBoundingBox._2 - getBoundingBox._1) / 2) - ((myc2.getBoundingBox._2 - myc2.getBoundingBox._1) / 2)
        val shiftY = getBoundingBox._4 - myc2.getBoundingBox._3

        overlap(myc2.translate(shiftX, shiftY))
    }

    //TODO: Write a function that will rotate each figure about the center of its bounding box in the canvas using
    // the angle `ang` defined in radians.
    // The writeup provided describes how to implement the rotation.
    // Hint: Write helper functions to rotate a Polygon and a circle. Then you can simply use
    // translation, followed by rotation of individual objects and translation back.
    def rotate(angRad: Double): MyCanvas = {
        val (minX, maxX, minY, maxY) = getBoundingBox
        val (x, y) = (((minX + maxX) / 2), ((minY + minX)/2))
        new MyCanvas(listOfObjects.map(_.rotate(angRad, x, y)))

    }

    def overlap(c2: MyCanvas): MyCanvas = {
        new MyCanvas(listOfObjects ++ c2.listOfObjects)
    }

    // Function to draw the canvas. Do not edit.
    def render(g: Graphics2D, xMax: Double, yMax: Double) = {
        val (lx1, ux1, ly1, uy1) = this.getBoundingBox
        val shiftx = -lx1
        val shifty = -uy1
        val scaleX = xMax/(ux1 - lx1  + 1.0)
        val scaleY = yMax/(uy1 - ly1 + 1.0)
        listOfObjects.foreach(f => f.render(g,scaleX, -scaleY, shiftx, shifty))
    }

    // DO NOT EDIT THE CODE BELOW
    override def toString: String = {
        listOfObjects.foldLeft[String] ("") { case (acc, fig) => acc ++ fig.toString }
    }

    // DO NOT EDIT
    def getListOfObjects: List[Figure] = listOfObjects

    // DO NOT EDIT
    def numPolygons: Int =
        listOfObjects.count {
            case Polygon(_) => true
            case _ => false }

    // DO NOT EDIT
    def numCircles: Int = {
        listOfObjects.count {
            case MyCircle(_,_) => true
            case _ => false }
    }
    // DO NOT EDIT
    def numVerticesTotal: Int = {
        listOfObjects.foldLeft[Int](0) ((acc, f) =>
            f match {
                case Polygon(lst1) => acc + lst1.length
                case _ => acc
            }
        )
    }
}
