package Suranjit;

import java.awt.AWTException;
import java.awt.Button;
import java.awt.Color;
import java.awt.Container;
import java.awt.Desktop;
import java.awt.Font;
import java.awt.Robot;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;

public class Suranjit extends JFrame {

    private Container c;
    private Button bt, bt2, bt3, bt4;

    Suranjit() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setBounds(400, 100, 550, 270);
        this.setTitle("Picchi");
        Font f = new Font("Arial", Font.BOLD, 18);

        c = this.getContentPane();
        c.setBackground(Color.black);

        c.setLayout(null);

        bt = new Button("Start menu");
        bt.setBounds(150, 100, 100, 50);
        bt.setFocusable(false);
        bt.setFont(f);
        bt.setForeground(Color.blue);
        bt.setBackground(Color.white);
        bt.setFocusable(false);
        c.add(bt);

//        bt2 = new Button("My Pc");
//        bt2.setBounds(300, 50, 200, 50);
//        bt2.setFocusable(false);
//        bt2.setFont(f);
//        bt2.setForeground(Color.blue);
//        bt2.setBackground(Color.white);
//        bt2.setFocusable(false);
//        c.add(bt2);
//
//        bt3 = new Button("Recycle Bin");
//        bt3.setBounds(40, 150, 200, 50);
//        bt3.setFocusable(false);
//        bt3.setFont(f);
//        bt3.setForeground(Color.blue);
//        bt3.setBackground(Color.white);
//        bt3.setFocusable(false);
//        c.add(bt3);
//
//        bt4 = new Button("Shuts down");
//        bt4.setBounds(300, 150, 200, 50);
//        bt4.setFocusable(false);
//        bt4.setFont(f);
//        bt4.setForeground(Color.blue);
//        bt4.setBackground(Color.white);
//        bt4.setFocusable(false);
//        c.add(bt4);

        bt.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent e) {
                bt.setBounds(e.getX(), e.getY(), 120, 50);
            }

            @Override
            public void mouseMoved(MouseEvent e) {

            }
        });
//        bt.addMouseListener(new MouseAdapter() {
//            @Override
//            public void mouseClicked(MouseEvent e) {
//                if (e.getClickCount() == 2) {
//                    bt.addActionListener(new ActionListener() {
//                        @Override
//                        public void actionPerformed(ActionEvent e) {
//                            try {
//                                Robot r = new Robot();
//                                r.keyPress(KeyEvent.VK_WINDOWS);
//                                r.keyRelease(KeyEvent.VK_WINDOWS);
//                            } catch (AWTException ex) {
//
//                            }
//                        }
//                    });
//                }
//            }
//        });
//
//        bt2.addMouseListener(new MouseAdapter() {
//            @Override
//            public void mouseClicked(MouseEvent e) {
//                if (e.getClickCount() == 2) {
//                    bt2.addActionListener(new ActionListener() {
//                        @Override
//                        public void actionPerformed(ActionEvent e) {
//                            try {
//                                Runtime.getRuntime().exec("explorer.exe /select," + "PC");
//                            } catch (IOException ex) {
//                                Logger.getLogger(Ashique.class.getName()).log(Level.SEVERE, null, ex);
//                            }
//                        }
//                    });
//                }
//            }
//        });
//
//        bt3.addMouseListener(new MouseAdapter() {
//            @Override
//            public void mouseClicked(MouseEvent e) {
//                if (e.getClickCount() == 2) {
//                    bt3.addActionListener(new ActionListener() {
//                        @Override
//                        public void actionPerformed(ActionEvent e) {
//                            try {
//                                Process p = Runtime.getRuntime().exec("cmd /c start shell:RecycleBinFolder");
//                                p.waitFor();
//                            } catch (InterruptedException ex) {
//                                Logger.getLogger(Ashique.class.getName()).log(Level.SEVERE, null, ex);
//                            } catch (IOException ex) {
//                                Logger.getLogger(Ashique.class.getName()).log(Level.SEVERE, null, ex);
//                            }
//                        }
//                    });
//                }
//            }
//        });
//
//        bt4.addMouseListener(new MouseAdapter() {
//            @Override
//            public void mouseClicked(MouseEvent e) {
//                if (e.getClickCount() == 2) {
//                    bt4.addActionListener(new ActionListener() {
//                        @Override
//                        public void actionPerformed(ActionEvent e) {
//
//                        }
//                    });
//                }
//            }
//        });
    }

    public static void main(String[] args) {
        Suranjit pc = new Suranjit();
        pc.setVisible(true);
        pc.setResizable(false);
    }
}
