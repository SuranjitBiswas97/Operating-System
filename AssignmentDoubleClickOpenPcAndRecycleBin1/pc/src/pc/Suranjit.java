package pc;

import java.awt.Button;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;

public class Suranjit extends JFrame {

    private final Container c;
    private Button bt, bt1;

    Suranjit() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setBounds(200, 100, 550, 270);
        this.setTitle("Reality");
        Font f = new Font("Arial", Font.BOLD, 18);

        c = this.getContentPane();
        c.setBackground(Color.green);

        c.setLayout(null);

        bt = new Button("My Pc");
        bt.setBounds(200, 50, 200, 50);
        bt.setFocusable(false);
        bt.setFont(f);
        bt.setForeground(Color.yellow);
        bt.setBackground(Color.white);
        bt.setFocusable(false);
        c.add(bt);

        bt1 = new Button("Recycle Bin");
        bt1.setBounds(200, 150, 200, 50);
        bt1.setFocusable(false);
        bt1.setFont(f);
        bt1.setForeground(Color.yellow);
        bt1.setBackground(Color.white);
        bt1.setFocusable(false);
        c.add(bt1);

        bt.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2) {
                    bt.addActionListener(new ActionListener() {
                        @Override
                        public void actionPerformed(ActionEvent e) {
                            try {
                                Runtime.getRuntime().exec("explorer.exe /select," + "PC");
                            } catch (IOException ex) {
                                Logger.getLogger(Suranjit.class.getName()).log(Level.SEVERE, null, ex);
                            }
                        }
                    });
                }
            }
        });

        bt1.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2) {
                    bt1.addActionListener(new ActionListener() {
                        @Override
                        public void actionPerformed(ActionEvent e) {
                            try {
                                Process p = Runtime.getRuntime().exec("cmd /c start shell:RecycleBinFolder");
                                p.waitFor();
                            } catch (InterruptedException ex) {
                                Logger.getLogger(Suranjit.class.getName()).log(Level.SEVERE, null, ex);
                            } catch (IOException ex) {
                                Logger.getLogger(Suranjit.class.getName()).log(Level.SEVERE, null, ex);
                            }
                        }
                    });
                }
            }
        });
    }

    public static void main(String[] args) {
        Suranjit pc = new Suranjit();
        pc.setVisible(true);
        pc.setResizable(false);
    }
}
